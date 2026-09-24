#include <iostream>
#include <vector>
#include <string>

//struuct to represent a robot
struct Robot {
    //robot name
    std::string name;
    //robot cost
    float cost;
};

//function to add a robot to the inventory
void addRobot(std::vector<Robot>& inventory, std::string name, float cost){
  //create a new robot
  Robot newRobot;
  newRobot.name = name;
  newRobot.cost = cost;
  //add this robot to our inventory
  inventory.push_back(newRobot);
}

//function to display the inventory of robots
void printInventory(std::vector<Robot> inventory){
  //print the inventory of robots, I recommend a for loop
  for (int i = 0; i < inventory.size(); i++){
    std::cout << "Name: " << inventory[i].name << ", Cost: " << inventory[i].cost << std::endl;
  }
}

int main(){
  //make the vector
  std::vector<Robot> inventory;
  //add robots to the inventory
  addRobot(inventory, "R2-D2", 1000.0f);
  addRobot(inventory, "C-3PO", 1500.0f);
  addRobot(inventory, "WALL-E", 2000.0f);
  //print the inventory
  printInventory(inventory);
  return 0;
}
