#include <iostream>

using namespace std;

const int MAX_ARG = 4;
const int MAX_OP = 11;
const int MAX_VAL = 11;

const string def0 = "(define v0 0)";
const string def1 = "(define v1 1)";
const string def2 = "(define v2 5)";
const string def3 = "(define v3 ())";
const string def4 = "(define v4 (0))";
const string def5 = "(define v5 (1))";
const string def6 = "(define v6 (5))";
const string def7 = "(define v7 (0 0))";
const string def8 = "(define v8 (0 1))";
const string def9 = "(define v9 (0 5))";
const string def10 = "(define v10 (5 5))";

string op(int i) {
	switch(i) {
		case 0:
			return "+";
			break;
		case 1:
			return "-";
			break;
		case 2:
			return "cons";
			break;
		case 3:
			return "head";
			break;
		case 4:
			return "tail";
			break;
		case 5:
			return "=";
			break;
		case 6:
			return "<";
			break;
		case 7:
			return "not";
			break;
		case 8:
			return "and";
			break;
		case 9:
			return "or";
			break;
		case 10:
			return "if";
			break;
	}
}

string val(int i) {
	switch(i) {
		case 0:
			return "v0";
			break;
		case 1:
			return "v1";
			break;
		case 2:
			return "v2";
			break;
		case 3:
			return "v3";
			break;
		case 4:
			return "v4";
			break;
		case 5:
			return "v5";
			break;
		case 6:
			return "v6";
			break;
		case 7:
			return "v7";
			break;
		case 8:
			return "v8";
			break;
		case 9:
			return "v9";
			break;
		case 10:
			return "v10";
			break;
	}
}

void definitions() {
	cout << def0 <<endl;
	cout << def1 <<endl;
	cout << def2 <<endl;
	cout << def3 <<endl;
	cout << def4 <<endl;
	cout << def5 <<endl;
	cout << def6 <<endl;
	cout << def7 <<endl;
	cout << def8 <<endl;
	cout << def9 <<endl;
	cout << def10 <<endl;
}

void game_generator() {
	for(int m = 0; m < MAX_ARG; ++m) {
		for(int n = 0; n < MAX_OP; ++n) {
			for(int i = 0; i < MAX_VAL; ++i) {
				if(m > 0){
					for(int j = 0; j < MAX_VAL; ++j) {
						if(m > 1) {
							for(int k = 0; k < MAX_VAL; ++k) {
								if(m > 2){
									for(int l = 0; l < MAX_VAL; ++l) {
										cout <<"(" << op(n) << " " << val(i) << " " << val(j) << " " << val(k) << " " << val(l) << ")" << endl;
									}
								}
								else {
										cout <<"(" << op(n) << " " << val(i) << " " << val(j) << " " << val(k) << ")" << endl;
								}
							}
						}
						else {
							cout <<"(" << op(n) << " " << val(i) << " " << val(j) << ")" << endl;
						}
					}
				}
				else {
					cout <<"(" << op(n) << " " << val(i) << ")" << endl;
				}
			}
		}
	}
	cout << "****" << endl;
}

/*void solution_generator() {
	for(int m = 0; m < MAX_ARG; ++m) {
		for(int n = 0; n < MAX_OP; ++n) {
			for(int i = 0; i < MAX_VAL; ++i) {
				if(m > 0){
					for(int j = 0; j < MAX_VAL; ++j) {
						if(m > 1) {
							for(int k = 0; k < MAX_VAL; ++k) {
								if(m > 2){
									for(int l = 0; l < MAX_VAL; ++l) {
										cout <<"(" << op(n) << " " << val(i) << " " << val(j) << " " << val(k) << " " << val(l) << ")" << endl;
									}
								}
								else {
										cout <<"(" << op(n) << " " << val(i) << " " << val(j) << " " << val(k) << ")" << endl;
								}
							}
						}
						else {
							cout <<"(" << op(n) << " " << val(i) << " " << val(j) << ")" << endl;
						}
					}
				}
				else {
					switch(n) {
						case 1:
							if(i == 0 or i == 1 or i == 2)
							break;
						case 3:
							break;
						case 4:
							break;
						case 7:
							break;
						default:
							cout << "indefinit" << endl;
							break;
					}
				}
			}
		}
	}
}*/

int main() {
	definitions();
	/*string in;
	cout << "Mode: " << endl;
	cout << "- Generate game (G)" << endl;
	cout << "- Generate solution (S)" << endl;
	cin >> in;
	while(in != "G" or in != "S") {
		cout << "Incorrect mode" << endl << endl;
		cout << "Mode: " << endl;
		cout << "- Generate game (G)" << endl;
		cout << "- Generate solution (S)" << endl;
		cin >> in;
	}
	if(in == "G") {*/
		game_generator();
	/*}
	else {
		solution_generator();
	}*/
}