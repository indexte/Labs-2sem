#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>

using namespace std;

class mob {
public:
	string name;
	int hp;
	int damage;
	double ability_chance;
	int ability_type;
	int id;
	int time;

	mob() {
		name = "No data";
		hp = 0;
		damage = 0;
		ability_chance = 0;
		ability_type = 0;
		id = 0;
		time = 0;
	}
	mob(string name, int hp, int damage, double ability_chance, int ability_type, int id, int time) {
		this->name = name;
		this->hp = hp;
		this->damage = damage;
		this->ability_chance = ability_chance;
		this->ability_type = ability_type;
		this->id = id;
		this->time = time;
	}
};


int main() {
	string path = "myFile.txt";
	string path_bin = "myFile.dat";

	string name;
	int hp;
	int damage;
	double ability_chance;
	int ability_type;
	int abilityType;
	int id;
	int time;

	ofstream fout;
	fout.open(path, ofstream::app);

	cout << "Please add your first element" << endl;


		cout << "Enter monster's name" << endl;
		name = "Monster_1";
		cout << name << endl;

		cout << "Enter monster's health points" << endl;
		hp = 100;
		cout << hp << endl;

		cout << "Enter monster's damage" << endl;
		damage = 20;
		cout << damage << endl;

		cout << "Enter monster's ability chance (0 to 1)" << endl;
		ability_chance = 0.1;
		cout << ability_chance << endl;

		cout << "Choose monster's ability type" << endl;
		cout << "Enter 1 for Double damage" << endl;
		cout << "Enter 2 for Repeat atack" << endl;
		cout << "Enter 3 for Healing" << endl;
		cout << "Enter 4 for Freeze the enemy" << endl;
		ability_type = 1;
		cout << "Ability type is Double damage" << endl;

		cout << "Enter monster's ID" << endl;
		id = 1;
		cout << id << endl;

		cout << "Enter spawn time (in seconds)" << endl;
		time = 1000;
		cout << time << endl;

		//çàïèñ ó ôàéë â òåêòîâîìó âèãëÿäi

		fout << "---------------------------------------------------" << endl;
		fout << "Monster's name: " << name << endl;
		fout << "Health points: " << hp << endl;
		fout << "Damage: " << damage << endl;
		fout << "Ability chance: " << ability_chance << endl;
		fout << "Ability type: " << ability_type << endl;
		fout << "ID: " << id << endl;
		fout << "Spawn time: " << time << endl;


		//äîäàâàííÿ ó ôàéë â áiíàðíîìó âèãëÿäi

		ofstream fout_bin;
		fout_bin.open(path_bin, ofstream::app);
		fout_bin.write((char*)&mob(name, hp, damage, ability_chance, ability_type, id, time), sizeof(mob));
		fout_bin.close();

		cout << "Done!" << endl;


	//ç÷èòóâàííÿ ç ôàéëó

	ifstream fin_bin;
	fin_bin.open(path_bin);

	vector<mob> myVector;

	mob mobs;

	while (fin_bin.read((char*)&mobs, sizeof(mob))) {
		myVector.push_back(mobs);
	}

	fout.close();
	fin_bin.close();

	//âèâiä ââåäåíèõ äàíèõ

	for (vector<mob>::iterator i = myVector.begin(); i < myVector.end(); i++) {
		cout << "---------------------------------------------------" << endl;
		cout << "Mob: " << i->name << endl;
		cout << "Health points: " << i->hp << endl;
		cout << "Damage: " << i->damage << endl;
		cout << "Ability chance: " << i->ability_chance << endl;
		cout << "Ability type: " << i->ability_type << endl;
		cout << "ID: " << i->id << endl;
		cout << "Spawn time: " << i->time << endl;
	}

	//ïîøóê åëåìåíòó çà iìåíåì

	vector<mob> find_name;

	cout << "Enter name to find element" << endl;

	string findname;
	findname = "Monster_1";
	cout << findname << endl;

	copy_if(myVector.begin(), myVector.end(), back_inserter(find_name), [&findname](const mob &m) {
		return m.name == findname;
	});
	if (find_name.size() == 0) {
		cout << "Nothing found" << endl;
	}
	else {
		for (vector<mob>::iterator i = find_name.begin(); i < find_name.end(); i++) {
			cout << "---------------------------------------------------" << endl;
			cout << "Mob: " << i->name << endl;
			cout << "Health points: " << i->hp << endl;
			cout << "Damage: " << i->damage << endl;
			cout << "Ability chance: " << i->ability_chance << endl;
			cout << "Ability type: " << i->ability_type << endl;
			cout << "ID: " << i->id << endl;
			cout << "Spawn time: " << i->time << endl;
		}
	}

	//ïîøóê åëåìåíòó çà òèïîì ñïåöiàëüíîi àòàêè

	vector<mob> find_ability_type;

	cout << "Enter ability type to find element" << endl;

	int findability_type;
	findability_type = 1;
	cout << findability_type << endl;

	copy_if(myVector.begin(), myVector.end(), back_inserter(find_ability_type), [&findability_type](const mob &m) {
		return m.ability_type == findability_type;
	});

	if (find_ability_type.size() == 0) {
		cout << "Nothing found" << endl;
	}
	else {
		for (vector<mob>::iterator i = find_ability_type.begin(); i < find_ability_type.end(); i++) {
			cout << "---------------------------------------------------" << endl;
			cout << "Mob: " << i->name << endl;
			cout << "Health points: " << i->hp << endl;
			cout << "Damage: " << i->damage << endl;
			cout << "Ability chance: " << i->ability_chance << endl;
			cout << "Ability type: " << i->ability_type << endl;
			cout << "ID: " << i->id << endl;
			cout << "Spawn time: " << i->time << endl;
		}
	}

	//ïîøóê åëåìåíòó çà êiëüêiñòþ îäèíèöü àòàêè

	vector<mob> find_damage;

	cout << "Enter damage range to find element" << endl;

	int finddamage_min;
	int finddamage_max;

	cout << "Min: ";
	finddamage_min = 10;
	cout << finddamage_min << endl;
	cout << "Max: ";
	finddamage_max = 200;
	cout << finddamage_max << endl;

	copy_if(myVector.begin(), myVector.end(), back_inserter(find_damage), [&finddamage_min, &finddamage_max](const mob &m) {
		return m.damage >= finddamage_min && m.damage <= finddamage_max;
	});

	if (find_damage.size() == 0) {
		cout << "Nothing found" << endl;
	}
	else {
		for (vector<mob>::iterator i = find_damage.begin(); i < find_damage.end(); i++) {
			cout << "---------------------------------------------------" << endl;
			cout << "Mob: " << i->name << endl;
			cout << "Health points: " << i->hp << endl;
			cout << "Damage: " << i->damage << endl;
			cout << "Ability chance: " << i->ability_chance << endl;
			cout << "Ability type: " << i->ability_type << endl;
			cout << "ID: " << i->id << endl;
			cout << "Spawn time: " << i->time << endl;
		}
	}

	//ïîøóê åëåìåíòó çà ÷àñîì ïîÿâè ó ãði

	vector<mob> find_time;

	cout << "Enter spawn time (in seconds) to find element" << endl;

	int findtime;

	findtime = 12000;
	cout << findtime << endl;

	copy_if(myVector.begin(), myVector.end(), back_inserter(find_damage), [&findtime](const mob &m) {
		return m.time >= findtime;
	});

	if (find_damage.size() == 0) {
		cout << "Nothing found" << endl;
	}
	else {
		for (vector<mob>::iterator i = find_time.begin(); i < find_time.end(); i++) {
			cout << "---------------------------------------------------" << endl;
			cout << "Mob: " << i->name << endl;
			cout << "Health points: " << i->hp << endl;
			cout << "Damage: " << i->damage << endl;
			cout << "Ability chance: " << i->ability_chance << endl;
			cout << "Ability type: " << i->ability_type << endl;
			cout << "ID: " << i->id << endl;
			cout << "Spawn time: " << i->time << endl;
		}
	}
	return 0;
}
