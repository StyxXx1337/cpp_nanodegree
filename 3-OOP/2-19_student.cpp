#include <cassert>
#include <stdexcept>

/**************
 * Directions

    Add 3 private member variables to the class:
        Name
        Grade (e.g. 9th grade)
        Grade Point Average
    Write a public constructor function to set the private attributes.
    Create public member functions to set each of the member variables. Before setting the values verify that:
        Grade is from 0 (kindergarten) to 12
        GPA is from 0.0 to 4.0
        The function must either throw an exception if any of the invariants are violated
    Within the main() (outside of the class), declare an object of type Student and test out each of the member function calls.
********************************/

// TODO: Define "Student" class
class Student {
 public:
  // constructor
  Student(std::string name, int grade, float gpa): _name(name), _grade(grade), _gpa(gpa) {
      Validate();
  }
  // accessors
  std::string Name() const { return _name; }
  int Grade() const { return _grade; }
  float Gpa() const { return _gpa; }
  // mutators
  void Name(std::string name) { _name = name; Validate();}
  void Grade(int grade) { _grade = grade; Validate();}
  void Gpa(float point) { _gpa = point; Validate();}

 private:
  bool Validate(void);
  std::string _name;
  int _grade;
  float _gpa;
};

bool Student::Validate(void){
      if (_grade < 1 || _gpa <= 0){
          throw std::invalid_argument("Invalid arguments passed.");
      }
      return true;
  }

// TODO: Test
int main() {
    Student me = Student("It's me", 11, 4.45);
    assert(me.Grade() == 11);
    assert(me.Name() == "It's me");
    assert( abs(me.Gpa() - 4.45) < 0.0001 );

    bool failed {false};
    try{
        me.Grade(-10);
    }
    catch (...){
        failed = true;
    }
    assert(failed == true);

}