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



const int MAX_INT = 5;
const size_t MAX_PRINT = 20;
const size_t VEC_2_GEN_SIZE = MAX_INT;


vector<mob> count_sort(vector<mob> vec) {
	vector<vector<mob>*> count_vec(MAX_INT, NULL);
	//cout<<&(count_vec)<<endl;
	//cout<<& vec<<endl;

	  // elements from vec to the count_vec

	for (vector<mob>::iterator it = vec.begin(); it != vec.end(); ++it) {

		if (count_vec[it->ability_type] == NULL) {
			count_vec[it->ability_type] = new vector<mob>();
		}

		(*count_vec[it->ability_type]).push_back(*it);

		// append element to the created or existing array

	}
	vec.clear();

	// run over all counted data structure and write sorted data back to the vec


	for (vector<vector<mob>*>::iterator it = count_vec.begin(); it != count_vec.end(); ++it) {

		int count = 0;
		size_t i = 0;
		if (*(it) != NULL)
		{
			size_t s = (*(*it)).size();
			while (i < (*(*it)).size())
			{

				mob pt;
				pt.name = (*(*it)).at(i).name;
				pt.hp = (*(*it)).at(i).hp;
				pt.damage = (*(*it)).at(i).damage;
				pt.ability_chance = (*(*it)).at(i).ability_chance;
				pt.ability_type = (*(*it)).at(i).ability_type;
				pt.id = (*(*it)).at(i).id;
				pt.time = (*(*it)).at(i).time;
				vec.push_back(pt);

				i++;
				count++;
			}
		}
	}

	// release temporary created arrays
	for (vector<vector<mob>*>::iterator it = count_vec.begin(); it != count_vec.end(); ++it) {
		if (*it != NULL) {
			delete *it;
		}

	}
	return vec;
}
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

	bool back = false;
	while (!back) {
		cout << "Enter monster name" << endl;
		cin >> name;

		cout << "Enter monster health points" << endl;
		cin >> hp;

		cout << "Enter monster damage" << endl;
		cin >> damage;

		cout << "Enter monster's ability chance (0 to 1)" << endl;
		cin >> ability_chance;
		bool stop_while = false;
		while (!stop_while) {
			cout << "Choose monster ability type" << endl;
			cout << "Enter 1 for Double damage" << endl;
			cout << "Enter 2 for Repeat atack" << endl;
			cout << "Enter 3 for Healing" << endl;
			cout << "Enter 4 for Freeze the enemy" << endl;
			cin >> abilityType;

			switch (abilityType) {
			case 1:
				cout << "Ability type is Double damage" << endl;
				ability_type = 1;
				stop_while = true;
				break;
			case 2:
				cout << "Ability type is Repeat atack" << endl;
				ability_type = 2;
				stop_while = true;
				break;
			case 3:
				cout << "Ability type is " << endl;
				ability_type = 3;
				stop_while = true;
				break;
			case 4:
				cout << "Ability type is Freeze the enemy" << endl;
				ability_type = 4;
				stop_while = true;
				break;
			default:
				cout << "Try again" << endl;
				stop_while = false;
			}
		}

		cout << "Enter monster ID" << endl;
		cin >> id;

		cout << "Enter spawn time (in seconds)" << endl;
		cin >> time;

		fout << "---------------------------------------------------" << endl;
		fout << "Monster name: " << name << endl;
		fout << "Health points: " << hp << endl;
		fout << "Damage: " << damage << endl;
		fout << "Ability chance: " << ability_chance << endl;
		fout << "Ability type: " << ability_type << endl;
		fout << "ID: " << id << endl;
		fout << "Spawn time: " << time << endl;



		ofstream fout_bin;
		fout_bin.open(path_bin, ofstream::app);
		fout_bin.write((char*)&mob(name, hp, damage, ability_chance, ability_type, id, time), sizeof(mob));
		fout_bin.close();

		cout << "Done!" << endl;

		cout << "Press any key to show list or 0 to add another element" << endl;

		char choose_exit;
		cin >> choose_exit;
		if (choose_exit == '0') {
			back = false;
		}
		else {
			back = true;
		}
	}

	ifstream fin_bin;
	fin_bin.open(path_bin);

	vector<mob> myVector;

	mob mobs;

	while (fin_bin.read((char*)&mobs, sizeof(mob))) {
		myVector.push_back(mobs);
	}

	fout.close();
	fin_bin.close();

	//SORTING
	cout << "Choose sort type" << endl;
	cout << "Enter 1 to STL sort by damage points" << endl;
	cout << "Enter 2 to radix sort by health points" << endl;
	cout << "Enter 3 to counting sort by ability type" << endl;

	int choose_sort;
	cin >> choose_sort;

	switch (choose_sort) {
	case 1: 

		sort(myVector.begin(), myVector.end(), [](const mob &m1, const mob &m2) {
			return m1.damage < m2.damage;
		});

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
		break;
	case 2:

		break;
	case 3:
		size_t count = 0;

		cout << "Sorted vector" << endl;

		myVector = count_sort(myVector);

		for (vector<mob>::iterator i = myVector.begin(); i != myVector.end() && count < MAX_PRINT; ++i, ++count) {
			cout << "---------------------------------------------------" << endl;
			cout << "Mob: " << i->name << endl;
			cout << "Health points: " << i->hp << endl;
			cout << "Damage: " << i->damage << endl;
			cout << "Ability chance: " << i->ability_chance << endl;
			cout << "Ability type: " << i->ability_type << endl;
			cout << "ID: " << i->id << endl;
			cout << "Spawn time: " << i->time << endl;
		}
		break;
	}

	/*FIND BY..
	vector<mob> find_name;
	cout << "Enter name to find element" << endl;
	string findname;
	cin >> findname;
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
	vector<mob> find_ability_type;
	cout << "Enter ability type to find element" << endl;
	int findability_type;
	cin >> findability_type;
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
	vector<mob> find_damage;
	cout << "Enter damage range to find element" << endl;
	int finddamage_min;
	int finddamage_max;
	cout << "Min: ";
	cin >> finddamage_min;
	cout << "Max: ";
	cin >> finddamage_max;
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
	vector<mob> find_time;
	cout << "Enter spawn time (in seconds) to find element" << endl;
	int findtime;
	cin >> findtime;
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
	*/
	return 0;
}
