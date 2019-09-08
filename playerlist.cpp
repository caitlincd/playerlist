
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ArgumentManager.h"

using namespace std;

struct player {
	string name;
	player * next;
};

class list {
private:
	player * head; //points to first player on the list
public:
	list();
	void add(player p); //add player to list alphabetically
	void print_pos(ifstream &com, ofstream &out); //print names + positions of players in com file to out file
	~list();
};

list::list() {
	head = 0;
}

//add players to list in alphabetical order
void list::add(player p) {
	player * newPlayer = new player;
	if (head == 0) { //if list is empty
		head = newPlayer;
		head->name = p.name;
		head->next = 0;
	}
	else {
		player * cu = head; //save the head
		
		while (cu->next != 0 && p.name > cu->next->name) //until the last item in the list is reached or if p is after cu
			cu = cu->next; //move to the next item in the list
		
		newPlayer->name = p.name;

		if (p.name < cu->name && cu == head) { //if the new player needs to be at the front of the list
			newPlayer->next = head;
			head = newPlayer;
		}
		else {
			newPlayer->next = cu->next; //newPlayer will now point to the member after cu
			cu->next = newPlayer; //cu will now point to newPlayer
		}
	}
}

//print the players' name and position in the list from the com file to the out file
void list::print_pos(ifstream &com, ofstream &out) {
	player * cu = head;
	string curr_name;
	int pos = 0;
	while (getline(com, curr_name)) { //while the command file reads a name
		if (!curr_name.empty()) {
			while (cu != 0 && cu->name != curr_name) { //while the name does not match the current player on the list or the end of the list has not been reached
				cu = cu->next; //move to the next player
				pos++; //increase position on the list by 1
			}
			if (cu == 0) //if the player is not listed
				pos = -1;
			out << curr_name << ": " << pos << endl;
			//reset position and cu pointer to beginning
			pos = 0;
			cu = head;
		}
	}
}

list::~list() {
	delete head;
}

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	string input = am.get("input");
	string command = am.get("command");
	string output = am.get("output");
	ifstream in;
	ifstream com;
	ofstream out;

	in.open(input);
	com.open(command);
	out.open(output);

	list player_list;
	player p;
	string line;

	//read all lines of input file and add to player list
	while (getline(in, line)) {
		stringstream linestream(line);
		if (!line.empty()) {
			getline(linestream, p.name, ',');
			player_list.add(p);
		}
	}
	
	//print the selected players names and positions to an output file
	player_list.print_pos(com, out);

	in.close();
	com.close();
	out.close();

	return 0;
}

