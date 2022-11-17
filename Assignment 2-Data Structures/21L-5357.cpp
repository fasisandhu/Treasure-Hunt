#include <iostream>
#include <fstream>//filehandling
#include <conio.h>//getch
#include <Windows.h>//sleep
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define devil 'D'
#define gasper 'G'
#define portal 'P'
#define treasue 'T'
#define wall 'X'
#define quitkey1 113
#define quitkey2 81

template <class type>
class stack {
private:

	struct node {
		type data;
		node* next;
		node()
		{
			next = NULL;
		}
		node(type val, node* ptr = 0)
		{
			data = val; next = ptr;
		}
	};
	node* top;
public:
	stack()
	{
		top = 0;
	}
	~stack()
	{
		if (top != NULL)
		{
			node* p = top;
			while (p!=NULL)
			{
				p = top->next;
				delete top;
				top = p;
			}
		}
	}
	void topel(type&el)
	{
		if (top != NULL)
			el= top->data;
	}
	void push(type const element)
	{
		if (top == NULL)
		{
			top = new node(element, NULL);
		}
		else
		{
			top = new node(element, top);
		}
	}
	int retsize()
	{
		int c = 0;
		node* temp = top;
		while (temp != NULL)
		{
			c++; temp = temp->next;
		}return c;
	}
	void pop()
	{
		if (top != NULL)
		{
			if (top->next == NULL)
			{
				//el = top->data;
				delete top; top = NULL;
			}
			else
			{
				//el = top->data;
				node* temp = top;
				top = top->next;
				delete temp;
			}
		}
	}
	void print() const
	{
		node* temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	bool isEmpty() const
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}

};



class room {
	char** map;
	int x; int y;
	int scx, scy;
	bool treasure;
	int roomno;
public:
	room(char** r = NULL, int xx = 0, int yy = 0, int sx = 0, int sy = 0,bool t=false,int rr=0)
	{
		map = r; x = xx; y = yy; scx = sx; scy = sy; treasure = t; roomno = rr;
	}
	room(const room& obj)
	{
		x = obj.x; y = obj.y; scx = obj.scx; scy = obj.scy; treasure = obj.treasure; roomno = obj.roomno;
		map = new char* [x];
		for (int i = 0; i < x; i++)
			map[i] = new char[y];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				map[i][j] = obj.map[i][j];
			}
		}
	}
	room& operator=(room& obj)
	{
		x = obj.x; y = obj.y; scx = obj.scx; scy = obj.scy; treasure = obj.treasure; roomno = obj.roomno;
		map = new char* [x];
		for (int i = 0; i < x; i++)
			map[i] = new char[y];
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				map[i][j] = obj.map[i][j];
			}
		}
		return*this;
	}
	~room()
	{
		if (map != NULL)
		{
			for (int i = 0; i < x; i++)
				delete map[i];
			delete[] map;
		}
	}
	void setdimen(int x1,int y1)
	{
		x = x1; y = y1;
	}
	void setcoord(int x1, int y1)
	{
		scx = x1; scy = y1;
	}
	void getdimen(int& x1, int& y1)
	{
		x1 = x; y1 = y;
	}
	void getcoor(int& x1, int& y1)
	{
		x1 = scx; y1 = scy;
	}
	void setmaps(char** input)
	{
		map = new char* [x];
		for (int i = 0; i < x; i++)
		{
			map[i] = new char[y];
		}
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				map[i][j] = input[i][j];
			}
		}
	}
	void setroomno(int n)
	{
		roomno = n;
	}
	int getroomno()
	{
		return roomno;
	}
	void settreeasue(bool t)
	{
		treasure = t;
	}
	bool gettreasure()
	{
		return treasure;
	}
	char** getmap()
	{
		return map;
	}
	void print()
	{
		//system("cls");
		cout << "*";
		for (int i = 0; i < y; i++)
		{
			cout << "*";
		}
		cout << "*";
		cout << endl;

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (j == 0)
					cout << "*";
				if (map[i][j] == 'X')
				{
					cout << "|";
				}
				else if (map[i][j] == '0')
				{
					cout << " ";
				}
				else
					cout << map[i][j];
				if (j == y - 1)
					cout << "*";
			}cout << endl;
		}
		
		cout << "*";
		for (int i = 0; i < y; i++)
		{
			cout << "*";
		}
		cout << "*";
		cout << endl;
	}
	void print(int o,int p)
	{
		system("cls");
		cout << "*";
		for (int i = 0; i < y; i++)
		{
			cout << "*";
		}
		cout << "*";
		cout << endl;

		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (j == 0)
					cout << "*";
				if (i == o && j == p)
					cout << "@";
				else if (map[i][j] == 'X')
				{
					cout << "|";
				}
				else if (map[i][j] == '0')
				{
					cout << " ";
				}
				else
					cout << map[i][j];

				if (j == y - 1)
					cout << "*";
			}cout << endl;
		}

		cout << "*";
		for (int i = 0; i < y; i++)
		{
			cout << "*";
		}
		cout << "*";
		cout << endl;
	}
	void simpleprint()
	{
		system("cls");
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cout << map[i][j] << " ";
			}cout << endl;
		}cout << endl;
	}

	bool operator==(room& obj)
	{
		if (x != obj.x || y != obj.y || scx != obj.scx || scy != obj.scy)
		{
			return false;
		}
		else
		{
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					if (map[i][j] != obj.map[i][j])
						return false;
				}
			}
		}
		return true;

	}

};

class coordinates {
	int x, y;
public:
	coordinates(int x1 = 0, int y1 = 0)
	{
		x = x1; y = y1;
	}
	void setcoo(int x1, int y1)
	{
		x = x1; y = y1;
	}
	void getcood(int& x1, int& y1)
	{
		x1 = x; y1 = y;
	}
	bool operator==(coordinates obj)
	{
		return(x == obj.x && y == obj.y);
	}
};




class game {
	room* rooms=NULL;
	stack<room> roomSTACK;
	stack<coordinates>path;
	coordinates forportalmain;//needed for portal in reccur implementation
	int roomnum=0;
public:
	game()
	{
		forportalmain.setcoo(-1, -1);
	}
	game(stack<room> s,stack<coordinates> p,room* r=NULL,int rn=0)
	{
		forportalmain.setcoo(-1, -1);
		rooms = r; roomSTACK = s; path = p; roomnum = rn;
	}
	~game()
	{
		delete [] rooms;
	}
	void initalizer();
	void run();
	void filehandling();
	void movement();
	void recursion(room currentroom, int io);
	int movementreccur();
	void quit();
	void gasperfunc();
	void portalfunc();
	void treasurefunc(int xt,int yt);
	void printpath();
	void quitkeyfunc();
	room get_top_room();
	bool choice();
	void start();
};
void game::initalizer()
{
	filehandling();
	srand(time(NULL));
	int r = rand() % roomnum;
	roomSTACK.push(rooms[r]);//1st room push in stack
}
void game::run()
{
	initalizer();
	if (choice())
		movement();
	else
		recursion(get_top_room(), 1);
}
void game::recursion(room currentroom,int io)
{
	if (io==0)
	{
		return;
	}
	else
	{
		io=movementreccur();
		return recursion(get_top_room(), io);//main
	}
}
void game::movement()
{
	room currentroom;
	int c = 0; char** map=NULL;
	bool done = true;
	int x, y;
	int l, w;
	while (1)
	{
		if (done)
		{
			roomSTACK.topel(currentroom);
			int tx, ty; forportalmain.getcood(tx, ty);
			if (tx != -1 && ty != -1)
			{
				x = tx; y = ty;
				forportalmain.setcoo(-1, -1);
			}
			else
			currentroom.getcoor(x, y);
			currentroom.print(x, y);
			currentroom.getdimen(l, w);
			map = currentroom.getmap();
			done = false;
		}
		if (currentroom.gettreasure())
		{
			coordinates temp(-1,-1); 
			if (!path.isEmpty())
			{
				path.topel(temp);
			}
			coordinates temp1(x, y);
			if (!(temp == temp1))
			{
				path.push(temp1);
			}
		}
		c = 0;
		//fflush(stdin);//to clear buffer bef getch
		c = _getch();
		if (c == KEY_UP)
		{
			if (x > 0)//checks movement doesnot go out of bound
			{
				if (map[x - 1][y] == wall)
				{//do nothing
				}
				else if (map[x - 1][y] == devil)
				{
					//quit game
					quit(); break;
				}
				else if (map[x - 1][y] == portal)
				{
					//portal func
					portalfunc();
					done = true;
					
				}
				else if (map[x - 1][y] == gasper)
				{
					//gasper func
					gasperfunc(); done = true;
				}
				else if (map[x - 1][y] == treasue)
				{
					//quit game
					treasurefunc(x-1,y); 
					printpath();
					break;
				}
				else
					x = x - 1;
			}
		}
		else if (c == KEY_DOWN)
		{
			if (x < l - 1)
			{
				if (map[x + 1][y] == wall)
				{//do nothing
				}
				else if (map[x + 1][y] == devil)
				{
					//quit game
					quit(); break;
				}
				else if (map[x + 1][y] == portal)
				{
					//portal func
					portalfunc();
					done = true;
				}
				else if (map[x + 1][y] == gasper)
				{
					//gasper func
					gasperfunc(); done = true;

				}
				else if (map[x + 1][y] == treasue)
				{
					//quit game
					treasurefunc(x + 1, y);
					printpath();
					break;
				}
				else
					x = x + 1;
			}
		}
		else if (c == KEY_LEFT)
		{
			if (y > 0)
			{
				if (map[x][y - 1] == wall)
				{//do nothing
				}
				else if (map[x][y - 1] == devil)
				{
					//quit game
					quit(); break;
				}
				else if (map[x][y - 1] == portal)
				{
					//portal func
					portalfunc();
					done = true;
				}
				else if (map[x][y - 1] == gasper)
				{
					//gasper func
					gasperfunc(); done = true;

				}
				else if (map[x][y - 1] == treasue)
				{
					//quit game
					treasurefunc(x, y - 1);
					printpath();
					break;
				}
				else
					y = y - 1;
			}
			}
		else if (c == KEY_RIGHT)
		{
			if (y < w - 1)
			{
				if (map[x][y + 1] == wall)
				{//do nothing
				}
				else if (map[x][y + 1] == devil)
				{
					//quit game
					quit(); break;
				}
				else if (map[x][y + 1] == portal)
				{
					//portal func
					portalfunc();
					done = true;
				}
				else if (map[x][y + 1] == gasper)
				{
					//gasper func
					gasperfunc(); done = true;

				}
				else if (map[x][y + 1] == treasue)
				{
					//quit game
					treasurefunc(x, y + 1);
					printpath();
					break;
				}
				else
					y = y + 1;
			}
		}
		else if (c == quitkey1 || c == quitkey2)
		{	
			quitkeyfunc();
			break;
		}
		if (!roomSTACK.isEmpty())//bcz of portal if it empties stack at frist time tail
			currentroom.print(x, y);//main print
		else
			break;
		
	}
}
int game::movementreccur()
{
	int io = 0;
	char** map = NULL;
	room currentroom = get_top_room(); int x, y; int l, w;
	int tx, ty; forportalmain.getcood(tx, ty);
	if (tx != -1 && ty != -1)
	{
		x = tx; y = ty;
		forportalmain.setcoo(-1, -1);
	}
	else
	currentroom.getcoor(x, y);
	currentroom.print(x, y);
	currentroom.getdimen(l, w);
	map = currentroom.getmap(); int c;
	while (1)
	{
		if (currentroom.gettreasure())
		{
			coordinates temp(-1, -1);
			if (!path.isEmpty())
			{
				path.topel(temp);
			}
			coordinates temp1(x, y);
			if (!(temp == temp1))
			{
				path.push(temp1);
			}
		}
		c = 0;
		c = _getch();

		if (c == KEY_UP)
		{
			if (x > 0)//checks movement doesnot go out of bound
			{
				if (map[x - 1][y] == wall)
				{//do nothing
				}
				else if (map[x - 1][y] == devil)
				{
					//quit game
					quit(); io = 0; break;
				}
				else if (map[x - 1][y] == portal)
				{
					//portal func
					portalfunc();
					if (!roomSTACK.isEmpty())
						io = 1;
					else
					{
						io = 0;//sp case for portal
						//break;
					}
					break;
					

				}
				else if (map[x - 1][y] == gasper)
				{
					//gasper func
					gasperfunc(); io = 1; break;
				}
				else if (map[x - 1][y] == treasue)
				{
					//quit game
					treasurefunc(x - 1, y);
					printpath();
					io = 0;
					break;
				}
				else
					x = x - 1;
			}
		}
		else if (c == KEY_DOWN)

		{
			if (x < l - 1)
			{
				if (map[x + 1][y] == wall)
				{//do nothing
				}
				else if (map[x + 1][y] == devil)
				{
					//quit game
					quit(); io = 0; break;
				}
				else if (map[x + 1][y] == portal)
				{
					//portal func
					portalfunc();
					if (!roomSTACK.isEmpty())
						io = 1;
					else
					{
						io = 0;//sp case for portal
						//break;
					}
					break;
				}
				else if (map[x + 1][y] == gasper)
				{
					//gasper func
					gasperfunc(); io = 1; break;

				}
				else if (map[x + 1][y] == treasue)
				{
					//quit game
					treasurefunc(x + 1, y);
					printpath();
					io = 0;
					break;
				}
				else
					x = x + 1;
			}
		}
		else if (c == KEY_LEFT)
		{
			if (y > 0)
			{
				if (map[x][y - 1] == wall)
				{//do nothing
				}
				else if (map[x][y - 1] == devil)
				{
					//quit game
					quit(); io = 0; break;
				}
				else if (map[x][y - 1] == portal)
				{
					//portal func
					portalfunc();
					if (!roomSTACK.isEmpty())
						io = 1;
					else
					{
						io = 0;//sp case for portal
						//break;
					}
					break;
				}
				else if (map[x][y - 1] == gasper)
				{
					//gasper func
					gasperfunc(); io = 1; break;

				}
				else if (map[x][y - 1] == treasue)
				{
					//quit game
					treasurefunc(x, y-1);
					printpath();
					io = 0;
					break;
				}
				else
					y = y - 1;
			}
		}
		else if (c == KEY_RIGHT)
		{
			if (y < w - 1)
			{
				if (map[x][y + 1] == wall)
				{//do nothing
				}
				else if (map[x][y + 1] == devil)
				{
					//quit game
					quit(); io = 0; break;
				}
				else if (map[x][y + 1] == portal)
				{
					//portal func
					portalfunc();
					if (!roomSTACK.isEmpty())
						io = 1;
					else
					{
						io = 0;//sp case for portal
						//break;
					}
					break;
				}
				else if (map[x][y + 1] == gasper)
				{
					//gasper func
					gasperfunc(); io = 1; break;

				}
				else if (map[x][y + 1] == treasue)
				{
					//quit game
					treasurefunc(x , y+1);
					printpath();
					io = 0;
					break;
				}
				else
					y = y + 1;
			}
		}
		else if (c == quitkey1 || c == quitkey2)
		{
		quitkeyfunc(); io = 0;
			break;
		}
		currentroom.print(x, y);//main print
	}
	return io;
}
void game::quit()//clear the stack and game ends
{
	Sleep(5);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "          GAME END           " << endl;
	cout << "    DEVIL KILLED THE PLAYER " << endl;
	cout << "    Press any key to exit " << endl;
	//stack clearing
	int s = roomSTACK.retsize();
	for (int i = 0; i < s; i++)
	{
		roomSTACK.pop();
	}//stack empty
	int t; t = _getch();
	Sleep(5);
}
void game::gasperfunc()
{
	Sleep(5);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "    ROOM CHANGED     " << endl;
	int req=0;
	for (int i = 0; i < roomnum; i++)
	{
		if (rooms[i].gettreasure())
		{
			req = i;
		}
	}
	roomSTACK.push(rooms[req]);
	Sleep(300);
}
void game::portalfunc()
{
	srand(time(NULL));
	Sleep(5);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "          PORTAL ENTERED           " << endl;
	cout << "          TOSS IN PROCESS          " << endl;
	int toss = rand()%2;
	if (toss)//1---head
	{
		cout << "          HEAD         " << endl;
		cout << "     MOVING FORWARD         " << endl;
		int randroom = rand() % roomnum;
		int curr = 0;
		room temp1; roomSTACK.topel(temp1);
		for (int i = 0; i < roomnum; i++)
		{
			if (rooms[i] == temp1)
			{
				curr = i; break;
			}
		}

		while (randroom == curr)//so it doesnot move into same room
		{
			randroom = rand() % roomnum;
		}
		roomSTACK.push(rooms[randroom]);
		//finding the portal
		room temp;
		roomSTACK.topel(temp);
		char** m = temp.getmap(); int ii, jj; temp.getdimen(ii, jj);
		int px = 0, py = 0;
		for (int i = 0; i < ii; i++)
		{
			for (int j = 0; j < jj; j++)
			{
				if (m[i][j] == portal)
				{
					px = i; py = j;
					break;
				}

			}
		}
		int x=0, y=0; int check = 0;
		
		if (px - 1 != -1)
		{
			if (m[px - 1][py] == '0' && check == 0)//up
			{
				x = px - 1; check = 1;
				y = py;
			}

		}
		if (py+1!=jj)
		{
		
			if (m[px][py + 1] == '0' && check == 0)//right
			{
				x = px; check = 1;
				y = py + 1;
			}
		}
		if (py-1!=-1)
		{
			if (m[px][py - 1] == '0' && check == 0)//left
			{
				x = px; check = 1;
				y = py - 1;
			}
		}
		if (px + 1 != ii)
		{
			if (m[px + 1][py] == '0' && check == 0)//down
			{
				x = px + 1; check = 1;
				y = py;
			}
		}
		
		forportalmain.setcoo(x, y);
		Sleep(250);
		//cout << "    Press any key to exit " << endl;
		cout << "    Press enter to continue " << endl;
		//int t; t = _getch();
		/*int t; t = _getch(); */cin.clear(); cin.ignore(256, '\n');

		//return true;
	}
	else
	{
		cout << "          TAIL      " << endl;
		cout << "     MOVING BACKWARD         " << endl;
		int s=roomSTACK.retsize();
		if (s == 1)//so if first time means only 1 room the stack emties game ends
		{
			roomSTACK.pop();
			cout << "          GAME END           " << endl;
			cout << "  PORTAL KICKED U OUT OF HOUSE " << endl;
			//cout << "    Press any key to exit " << endl;
			cout << "    Press enter to continue " << endl;
			/*int t; t = _getch(); */cin.clear(); cin.ignore(256, '\n');
			//return true;
			//Sleep(5);
		}
		//else//commented after asking mam
		//{
		//	int sizeofstack = roomSTACK.retsize();
		//	if (s == 2)//to avoid stack emptying
		//	{
		//		room t1; roomSTACK.topel(t1);
		//		roomSTACK.pop();
		//		room t2; roomSTACK.topel(t2);
		//		roomSTACK.push(t1);
		//		roomSTACK.push(t2);
		//	}
		else
		{
			roomSTACK.pop();
			//finding the portal
			room temp; roomSTACK.topel(temp);
			char** m = temp.getmap(); int ii, jj; temp.getdimen(ii, jj);
			int px = 0, py = 0;
			for (int i = 0; i < ii; i++)
			{
				for (int j = 0; j < jj; j++)
				{
					if (m[i][j] == portal)
					{
						px = i; py = j;
						break;
					}

				}
			}
			int x = 0, y = 0;
			int check = 0;
			if (px - 1 != -1)
			{
				if (m[px - 1][py] == '0' && check == 0)//up
				{
					x = px - 1; check = 1;
					y = py;
				}

			}
			if (py + 1 != jj)
			{

				if (m[px][py + 1] == '0' && check == 0)//right
				{
					x = px; check = 1;
					y = py + 1;
				}
			}
			if (py - 1 != -1)
			{
				if (m[px][py - 1] == '0' && check == 0)//left
				{
					x = px; check = 1;
					y = py - 1;
				}
			}
			if (px + 1 != ii)
			{
				if (m[px + 1][py] == '0' && check == 0)//down
				{
					x = px + 1; check = 1;
					y = py;
				}
			}
			forportalmain.setcoo(x, y);
			//coordinates t(x, y);
			//if (!roomSTACK.retsize())
			//{
			//	cout << "          GAME END           " << endl;
			//	cout << "  PORTAL KICKED U OUT OF HOUSE " << endl;
			//}
			////cout << "    Press any key to exit " << endl;
			//else
			//{
			//	cout << "  MOVING TO PREV ROOM    " << endl;

			//}
			cout << "     MOVING TO PREV ROOM    " << endl;
			cout << "    Press enter to continue " << endl;
			/*int t; t = _getch(); */cin.clear(); cin.ignore(256, '\n');
			//return true;
	//	}
		//cout << "    Press any key to exit " << endl;
		//int t; t = _getch(); cin.ignore();
			Sleep(500);
		}

		//return false;
		//return true;
	}
}
void game::treasurefunc(int xt,int yt)
{
	Sleep(5);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "       TREASURE FOUND      " << endl;
	cout << "          YOU WON          " << endl;
	cout << "   TREASURE IS AT::"<<xt<<","<<yt<<" cooridinates" << endl;
	int req = 0;
	for (int i = 0; i < roomnum; i++)
	{
		if (rooms[i].gettreasure())
		{
			req = i;
		}
	}
	cout << "   IN ROOM::"<<req+1 << endl;
	cout << "    Press any key to exit " << endl;


	//stack clearing
	int s = roomSTACK.retsize();
	for (int i = 0; i < s; i++)
	{
		roomSTACK.pop();
	}//stack empty
	int t; t = _getch();
	Sleep(5);
}
void game::printpath()
{
	int req = 0;
	for (int i = 0; i < roomnum; i++)
	{
		if (rooms[i].gettreasure())
		{
			req = i;
		}
	}
	char** map = rooms[req].getmap();
	int l, w; rooms[req].getdimen(l, w); int s = path.retsize();
	//empty path stack
	coordinates* data = new coordinates[s];
	for (int i = 0; i < s; i++)
	{
		path.topel(data[i]);
		path.pop();
	}//path stack is empty all data is in data variable

	//for (int i = 0; i < s; i++)
	//{
	//	int xp, yp;
	//	data[i].getcood(xp, yp);
	//	cout << "x::" << xp << ",,," << "y:::" << yp << endl;
	//}

	system("cls");
	cout << "*";
	for (int i = 0; i < w; i++)
	{
		cout << "*";
	}
	cout << "*";
	cout << endl;

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (j == 0)
				cout << "*";
			//check if coordinated were crossed
			coordinates temp(i, j); int check = 0;
			for (int k = 0; k < s; k++)
			{
				int a, s1; data[k].getcood(a, s1);
				if (i == a && j == s1)
				{
					check = 1; break;
				}

			}
			if (map[i][j] == 'X')
			{
				cout << "|";
			}
			else if (check)
			{
				cout << "@";
			}
			else if (map[i][j] == '0')
			{
				cout << " ";
			}
			else if (map[i][j] == treasue)
			{
				cout << "@";//as user jumps on treasre
			}
			else
				cout << map[i][j];
			if (j == w - 1)
				cout << "*";
		}cout << endl;
	}

	cout << "*";
	for (int i = 0; i < w; i++)
	{
		cout << "*";
	}
	cout << "*";
	cout << endl;

}
void game::quitkeyfunc()
{
	Sleep(5);
	system("cls");
	cout << endl << endl << endl << endl;
	cout << "	 YOU PRESSED QUIT KEY          " << endl;
	cout << "         GAME END " << endl;
	cout << "    Press any key to exit " << endl;
	//stack clearing
	int s = roomSTACK.retsize();
	for (int i = 0; i < s; i++)
	{
		roomSTACK.pop();
	}//stack empty
	int t; t = _getch();
	Sleep(5);
}
room game::get_top_room()
{
	room temp; roomSTACK.topel(temp); return temp;
}
bool game::choice()
{
	int choice=1;
	cout << "1:Stack Implementation" << endl;
	cout << "2:Recurrsive" << endl;
	cout << "Enter 1 for stack or 2 for recurssive" << endl;
	cin >> choice;
	while (choice > 2 || choice < 1)
	{
		cout << "Enter again" << endl;
		cin >> choice;
	}
	start();
	if (choice == 1)
		return true;
	else
		return false;
}
void game::start()
{
	system("cls");
	cout << "  TREASURE HUNT" << endl;
	cout << "  T:TREASURE" << endl;
	cout << "  G:GASPER" << endl;
	cout << "  D:DEVIL" << endl;
	cout << "  P:PORTAL" << endl;
	cout << "  BEWARE OF PORTAL" << endl;
	cout << "  PRESS Q TO EXIT GAME AT ANY POINT" << endl;
	cout << "  PRESS ANY KEY TO START THE GAME" << endl;
	int c; c = _getch();
	cin.clear(); cin.ignore(256, '\n');
}
void game::filehandling()
{
	fstream file;
	file.open("hauntedhouse.txt");
	////////////////////////////////////////////////////////////////
	roomnum = 0;
	////////////////////////////////////////////////////////////////
	bool done = true; int c = 0; string* names = NULL;
	while (!file.eof())
	{
		if (done)
		{
			file >> roomnum;
			names = new string[roomnum]; done = false;
		}
		else
		{
			file >> names[c];
			c++;
		}
	}
	file.close();
	int count = 0;
	int x = 0, y = 0; char** map = NULL;
	////////////////////////////////////////////////////////////////
	rooms = new room[roomnum];
	////////////////////////////////////////////////////////////////

	while (count != roomnum)
	{
		file.open(names[count]);
		done = true;
		while (!file.eof())
		{
			if (done)
			{
				int x1, y1;
				file >> x1; file.ignore();
				file >> y1; file.ignore();
				x = x1; y = y1;
				map = new char* [x1];
				for (int i = 0; i < x1; i++)
					map[i] = new char[y1];

				rooms[count].setdimen(x1, y1);
				file >> x1; file.ignore();
				file >> y1; file.ignore();
				rooms[count].setcoord(x1, y1);
				done = false;
			}
			else
			{
				for (int i = 0; i < x; i++)
				{
					for (int j = 0; j < y; j++)
					{
						file >> map[i][j];
						if (map[i][j] == 'T')
						{
							rooms[count].settreeasue(true);
						}
					}
				}
				rooms[count].setmaps(map);
				rooms[count].setroomno(count + 1);
				//rooms[count].print();
				file.ignore();
			}
		}file.close();
		count++;
	}

}



int main()
{
	game obj; 
	obj.run();
	system("pause");
	return 0;
}