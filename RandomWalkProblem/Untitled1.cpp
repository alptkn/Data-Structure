#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;





bool check_size(int N, int M){
	if((N > 2 && N < 40) && (M > 2 && M < 21))
		return true;
	else
		return false;
}


class Room{
	int **field;
	int x_max;
	int y_max;
	bool check_init_size(int N, int M);
	bool check_border(int x, int y);
	public:
		
		void init(int M, int N);
		~Room();
		void print();
		bool increment(int x, int y);
		bool check();
		
};
bool Room::check_border(int x, int y){
	if(x >= 0 && x < x_max && y >= 0 && y < y_max)
		return true;
	else
		return false;
}
void Room::init(int N, int M){
	
	x_max = N;
	y_max = M;
	field = new int*[N];
	for(int i = 0; i < N; i++)
		field[i] = new int[M];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			field[i][j] = 0;
		}
	}	
}
Room::~Room(){
	for(int i = 0; i < x_max; i++)
		delete[] field[i];
	delete[] field;
}
void Room::print(){
	for(int i = 0; i < x_max; i++){
			for(int j = 0; j < y_max; j++){
				cout <<field[i][j]<< "|";
			}
			cout << endl;
	}
}
bool Room::increment(int x, int y){
	if(check_border(x,y)){
		field[x][y]++;
		return true;
	}
	else
		return false;
		
}
bool Room::check(){
	bool flag = true;
	for(int i = 0; i < x_max; i++){
		for(int j = 0; j < y_max; j++){
			if(field[i][j] == 0)
				flag = false;
			if(!flag)
				return flag;
		}
	}
	return flag;
}
class Bug{
	int pos_x, pos_y;
	Room field;
	int rand_generator();
	int legal_moves;
	public:
	bool init(int x, int y, int N, int M);
	void move();
	bool check_field(){
		return field.check();
	}
	void bug_print(){
		field.print();
		cout << endl;
		cout << "Leagal moves: " << legal_moves << endl;
	}
	
};
int Bug::rand_generator(){
	return 1 + (rand() % (8));
}
bool Bug::init(int x, int y, int N, int M){
	if(x < 0 || y < 0 ||x >= N || y >= M)
		return false;
	legal_moves = 0;
	pos_x = x;
	pos_y = y;
	if(check_size(N,M)){
		field.init(N,M);
		return true;
	}
	else
		return false;
	
}
void Bug::move(){
		int num = rand_generator();
		//cout << num << endl;
		if(num == 1){
			if(field.increment(pos_x-1, pos_y-1)){
				legal_moves++;
				pos_x--;
				pos_y--;
			}
				
		}
		else if(num == 2){
			if(field.increment(pos_x-1, pos_y)){
				legal_moves++;
				pos_x--;
			}
				
		}
			
		else if(num == 3){
			if(field.increment(pos_x-1, pos_y+1)){
				legal_moves++;
				pos_x--;
				pos_y++;
			}
				
		}
			
		else if(num == 4){
			if(field.increment(pos_x, pos_y-1)){
				legal_moves++;
				pos_y--;
			}
				
		}
			
		else if(num == 5){
			if(field.increment(pos_x, pos_y+1)){
				legal_moves++;
				pos_y++;
			}
				
		}
			
		else if(num == 6){
			if(	field.increment(pos_x+1, pos_y-1)){
				legal_moves++;
				pos_x++;
				pos_y--;
			}
				
		}
		
		else if(num == 7){
			if(field.increment(pos_x+1, pos_y)){
				legal_moves;
				pos_x++;
			}
				
		}
			
		else{
			if(field.increment(pos_x+1,pos_y+1)){
				legal_moves++;
				pos_x++;
				pos_y++;
			}
				
		}
			
}


class App{
	Bug bug;
	int max_iter = 50000;
	public:
		bool init(int x,int y,int N,int M);
		void play();
};
bool App::init(int x,int y,int N,int M){
	return bug.init(x,y,N,M);
}
void App::play(){
	for(int i = 0; i < max_iter; i++){
		bug.move();
		if(bug.check_field()){
			bug.bug_print();
			return;
		}
	}
	bug.bug_print();	
}
int main(){
	App app;
	int N,M,x,y;
	cout << "Please enter the size of the field! and initial location of the bug !" <<endl;
	cin >> N;
	cin >> M;
	cin >> x;
	cin >> y;
	if(!app.init(x,y,N,M)){
		cout << "Size of the field or initial point of bug is invalid!!!" << endl;
		return 0;
	}
	app.play();
	
}






