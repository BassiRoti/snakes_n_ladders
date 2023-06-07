#include<iostream>
#include<queue>
using namespace std;

class player
{
public:
	string name;
	int score;
	player()
	{
		name = '/0';
		score = 0;
	}
};

void ascendingdisplay(queue<player> obj, int size)
{
	cout << endl << endl << "   GAME ENDED" << endl << endl;
	cout << "The winners in ascending order are: " << endl;

	player garbage;
	queue<player> temp;
	int tempsize = size;
	while (!obj.empty())
	{
		for (int i = 1; i < tempsize; i++)
		{
			garbage = obj.front();
			obj.pop();
			obj.push(garbage);
		}
		temp.push(obj.front());
		obj.pop();
		--tempsize;

	}

	for (int i = 0; i < size; i++)
	{
		cout << temp.front().name << endl;
		garbage = temp.front();
		temp.pop();
		temp.push(garbage);


	}
}



void game(queue<player>& object, int participants)
{
	cout << endl << endl;
	srand(time(0));
	cout << "Game Starts ! " << endl << endl;
	int old;
	int news = 0;
	char input;
	queue<player>wins;
	queue<player> garbage;
	bool check = true;
	while (object.size() > 1)
	{
		cout << "Turn of player " << object.front().name << endl;
		cout << "Press A to roll the dice" << endl;
		cin >> input;
		if (input == 'a')
		{
			old = object.front().score;
			news = old + (rand() % (6 - 1) + 1);
			cout << endl;
			cout << "dice rolled! " << endl;

		}
		if (news == 100)
		{
			object.front().score = news;
			cout << endl << object.front().name << " reached a score of 100 and won, Congrats! " << endl;
			wins.push(object.front());
			object.pop();
			check = false;
		}

		if (news > 100)
		{
			cout << "Oops! Score of " << object.front().name << " exceeded, try again in next move " << endl;
			cout << "your score is " << object.front().score << endl;
			garbage.push(object.front());
			object.pop();
			object.push(garbage.front());
			garbage.pop();
			check = false;
		}
		if (news == 20 || news == 60)
		{
			if (news == 20) {
				cout << endl << object.front().name << " met a ladder, score increased to 40" << endl;
				news = 40;
			}
			else {
				cout << endl << object.front().name << " met a ladder, score increased by 75" << endl;
				news = 75;
			}

			object.front().score = news;
			garbage.push(object.front());
			object.pop();
			object.push(garbage.front());
			garbage.pop();
		}
		else if (news == 50 || news == 90)
		{
			if (news == 50) {
				cout << endl << object.front().name << " met a snake, score decreased to 40" << endl;
				news = 40;
			}
			else {
				cout << endl << object.front().name << " met a snake, score decreased by 79" << endl;
				news = 79;
			}

			object.front().score = news;
			garbage.push(object.front());
			object.pop();
			object.push(garbage.front());
			garbage.pop();
		}
		else if (check)
		{
			object.front().score = news;
			garbage.push(object.front());
			object.pop();
			object.push(garbage.front());
			garbage.pop();
			cout << "New score is " << news << endl;
		}
		check = true;


	}


	//display(wins,participants);
	ascendingdisplay(wins, participants - 1);

}




int main()
{
	queue<player> obj;
	int players;
	player garbage;
	cout << "     WELCOME   " << endl;
	cout << "Enter number of players: ";
	cin >> players;
	string names;
	for (int i = 0; i < players; i++)
	{
		cout << "Enter player " << i + 1 << " name: ";
		cin >> names;
		garbage.name = names;
		obj.push(garbage);
	}

	game(obj, players);
}