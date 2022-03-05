#include "route_planner.h"
#include <algorithm>
#include <vector>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

    // TODO 2: Use the m_Model.FindClosestNode method to find the closest nodes to the starting and ending coordinates.
    // Store the nodes you find in the RoutePlanner's start_node and end_node attributes.
  start_node = &m_Model.FindClosestNode(start_x, start_y);
  end_node = &m_Model.FindClosestNode(end_x, end_y);

}


// TODO 3: Implement the CalculateHValue method.
// Tips:
// - You can use the distance to the end_node for the h value.
// - Node objects have a distance method to determine the distance to another node.

float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
  float dist = node->distance(*end_node);
  return (dist);
}


// TODO 4: Complete the AddNeighbors method to expand the current node by adding all unvisited neighbors to the open list.
// Tips:
// - Use the FindNeighbors() method of the current_node to populate current_node.neighbors vector with all the neighbors.
// - For each node in current_node.neighbors, set the parent, the h_value, the g_value.
// - Use CalculateHValue below to implement the h-Value calculation.
// - For each node in current_node.neighbors, add the neighbor to open_list and set the node's visited attribute to true.

void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
  current_node->FindNeighbors();
  // loop throught each neighbor in neighbors
  for (auto neighbor : current_node->neighbors){
    // add the attributes to node
    neighbor->parent = current_node;
    neighbor->h_value = RoutePlanner::CalculateHValue(neighbor);
    //
    neighbor->g_value = current_node->g_value + current_node->distance(*neighbor);
    neighbor->visited = true;
    // add to open list
    open_list.push_back(neighbor);
  }
}


// TODO 5: Complete the NextNode method to sort the open list and return the next node.
// Tips:
// - Sort the open_list according to the sum of the h value and g value.
// - Create a pointer to the node in the list with the lowest sum.
// - Remove that node from the open_list.
// - Return the pointer.

// Compare function for the sort function
bool Compare(const RouteModel::Node* n1, const RouteModel::Node* n2){
  return ((n1->g_value + n1->h_value) > (n2->g_value + n2->h_value));
}

RouteModel::Node *RoutePlanner::NextNode() {

  sort(this->open_list.begin(), this->open_list.end(), Compare);
  // lowest sum ptr
  auto lowest_sum = open_list.back();
  // delete item from open_list
  open_list.pop_back();

  return lowest_sum;
}


// TODO 6: Complete the ConstructFinalPath method to return the final path found from your A* search.
// Tips:
// - This method should take the current (final) node as an argument and iteratively follow the
//   chain of parents of nodes until the starting node is found.
// - For each node in the chain, add the distance from the node to its parent to the distance variable.
// - The returned vector should be in the correct order: the start node should be the first element
//   of the vector, the end node should be the last element.

std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
    // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;

    // TODO: Implement your solution here.
    // parent of beginning of path is nullptr
  while(current_node->parent != nullptr){
    path_found.push_back(*current_node);

    // add distance of current node to parent to total
    distance += current_node->distance(*current_node->parent);

    // make parent current_node
    current_node = current_node->parent;
    if (current_node == nullptr){
      std::cout << "Start Node:" << current_node->x << " : " << current_node->y << std::endl;
    }
  }
  // add start also to the list.
  path_found.push_back(*current_node);
  // correct the order of the vector end->beg ==> beg->end
  reverse(path_found.begin(), path_found.end());


  distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
  return path_found;

}


// TODO 7: Write the A* Search algorithm here.
// Tips:
// - Use the AddNeighbors method to add all of the neighbors of the current node to the open_list.
// - Use the NextNode() method to sort the open_list and return the next node.
// - When the search has reached the end_node, use the ConstructFinalPath method to return the final path that was found.
// - Store the final path in the m_Model.path attribute before the method exits. This path will then be displayed on the map tile.

void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;


    // TODO: Implement your solution here.
  // Initialize the start_node
  start_node -> parent = current_node;
  current_node = start_node;

// ===== For debugging ====
  if (current_node->parent == nullptr){
  	std::cout << "Parent is nullpt" << std::endl;
  }
  std::cout << "Start from X:" << current_node->x << " and Y:" << current_node->y << std::endl;
// =========================

  // Fill the values of the start_node
  current_node->g_value = 0;
  current_node->h_value = CalculateHValue(current_node);

  // Push it into the open list
  open_list.push_back(current_node);

  // ========= For debugging
  std::cout << "Searching for X:" << end_node->x << " and Y:" << end_node->y << std::endl;
// =========================

  while (open_list.size() > 0){
    // get next node
    current_node = NextNode();

    // if next node is target -> end
    // std::cout << "Current Node-X: " << current_node->x << " and Node-Y: " << current_node->y << std::endl;
    if ((current_node->x == end_node->x) && (current_node->y == end_node->y)){

      // ==== For debugging ====
      std::cout << "Found Node-X: " << current_node->x << " and Node-Y: " << current_node->y << std::endl;
      // =======================

      m_Model.path = ConstructFinalPath(current_node);
      break;
    }

    // Add neighbors to the search area.
    AddNeighbors(current_node);
  }

  std::cout << "No path found!" << "\n";
}