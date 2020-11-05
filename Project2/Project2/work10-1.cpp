#include <iostream>
#include <string>
#include <atlstr.h>


#include <fstream>
using namespace std;

int main() {
	string data;
	string data2;
	char instr[8][8] = { "SEGMENT","ASSUME","MOV","ADD","SUB","CMP","JNE","INT" };
	char regi[21][3] = { "AX","BX","CX","DX","AH","AL","BH","BL","CH","CL","DH","DL","CS","IP","SP","BP","SS","SI","DI","DS","ES" };
	string labelname[100] = { "NULL" };
	ifstream in;
	in.open("my.asm");

	int j, k;
	int r = 0;
	int labelvalue[100] = { 0, };
	int labelnum[100] = { 0, };
	int count[1000] = { 0, };
	int check = 0;
	int end = 0;
	int flag;
	int labelend = 0;
	char tmp[200][20] = { 0, };

	int i = 0;
	while (!in.eof()) {
		getline(in, data);
		if (data[0] >= 65 && data[0] <= 90) {

			labelvalue[r] = count[i];
			//cout << count[i] << endl;
			if (labelvalue[r] != 0) {
				labelvalue[r] += 1;
			}
			//cout << labelvalue[r] << endl;
			if (i == 0) {
				labelnum[r] = i;
			}
			else {
				labelnum[r] = i + 1;
			}
			//cout << labelnum[r] << endl;
			r++;

		}
		if (i != 0) {
			if (data[0] != '	' && data[0] != ' ' && data[0] != ':') {
				i++;
				k = 0;
			}
		}
		for (j = 0, k = 0; j < data.length(); k++, j++) {
			flag = 0;
			if (data[j] == '	' || data[j] == ' ' || data[j] == ':') {
				i++;
				k = 0;
				flag = 1;
			}
			if (data[j] != ',') {
				tmp[i][k] = data[j];
			}

			if ((tmp[i][0] >= 48 && tmp[i][0] <= 57) || (tmp[i][0] >= 65 && tmp[i][0] <= 90)) {
				if (k == 0) {
					count[i] = check++;
				}

			}
			if (flag == 1) {
				i++;
				k = -1;
			}
			 


		}
		
		
		end = i;

	}


	for (int i = 0; i < r; i++) {
		if (i == 0) {
			labelname[i] = tmp[labelnum[i]];
		}
	

		for (int j = 0; j < i; j++) {
			if (tmp[labelnum[i]] == labelname[j]) {
				break;
			}
			labelname[i] = tmp[labelnum[i]];
		}
		labelend = i;
	}

	for (int i = 0; i < labelend; i++) {
		cout << labelname[i] << " " << labelvalue[i]<<endl;
		
	}

	in.close();


	ifstream in2;
	in2.open("my.asm");
	int tmpget = 0;
	int get = 0;
	string ff = "[";
	string ee = "]";
	while(!in2.eof()){
		getline(in2, data2);

		for (int i = 0; i < labelend; i++) {
			int length = labelname[i].length();
			string changetmp;	
			changetmp = to_string(labelvalue[i]);
			changetmp += ee;
			changetmp = ff + changetmp;
			if (data2.find(labelname[i]) != string::npos) {
				tmpget = data2.find(labelname[i]);
				if (data2[tmpget + length]>=65&& data2[tmpget + length]<=90) {
					
				}
				else {
					if (data2[0] >= 65 && data2[0] <= 90) {

					}
					else {
						get = data2.find(labelname[i]);
						data2.replace(data2.begin()+get, data2.begin()+get+length, changetmp.begin(),changetmp.end());
						
					}
					
				}
			
			}

		}
		cout<< data2 << endl;
	}
		

	/*for (int i = 0; i < end+1; i++) {
		if (tmp[i][0] != '	' && tmp[i][0] != ' ' && tmp[i][0] != ':'&& (tmp[i][0] >= 48 && tmp[i][0] <= 57) || (tmp[i][0] >= 65 && tmp[i][0] <= 90)) {
			cout << tmp[i] << " " <<i<<" "<< count[i] << endl;
		}
	}*/
	
}