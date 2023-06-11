#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void write_f(ofstream& write) 
{
    write << "Student ID\tPasswords" << endl;
    write << "l1f22bscs0036\tazzfkk" << endl;
	write << "l1f22bscs0014\tsdfghy" << endl;
    write << "l1f22bscs0020\tkhhert" << endl;
    write << "l1f22bscs0017\tyuownj" << endl;
    cout << "Valid Details" << endl;
    cout << "Student ID\tPasswords" << endl;
    cout << "l1f22bscs0036\tazzfkk" << endl;
	cout << "l1f22bscs0014\tsdfghy" << endl;
    cout << "l1f22bscs0020\tkhhert" << endl;
    cout << "l1f22bscs0017\tyuownj" << endl;
}
bool compare(char *a, char *b)
{
	int l1 = strlen(a), l2 = strlen(b);
	if(l1 != l2)
	{
		return false;
	}
	else
	{
		for(int i = 0; i < l1; i++)
		{
			if(b[i] != a[i])
			{
				return false;
			}
		}
		return true;
	}
}
bool input(char* id, char* pass) 
{
    cout << "Enter ID: ";
    cin.getline(id, 20);
    cout << "Enter password: ";
    cin.getline(pass, 10);
    ifstream read("Student Accounts.txt");
    if (!read) 
	{
        cout << "Error\n";
        return false;
    }
    else 
	{
        bool valid = false;
        char waste[50], id1[20], pass1[10];
        read.getline(waste, 50);
        while (!read.eof()) 
        {
            read.getline(id1, 20,'\t');
            read.getline(pass1, 10);
            if (compare(id, id1) && compare(pass, pass1))
            {
                valid = true;
                break;
            }
        }
        read.close();
        if (valid)
        {
        	cout << "Login Succesful\n";
            return true;
        }
        else
        {
            cout << "Invalid ID or Password\n";
            return false;
        }
    }
}
char display() 
{
    char n;
    cout << "\n\t\tOnline Quiz" << endl;
    cout << "Select any Subject" << endl;
    cout << "1) English\t2) Maths\t3) Science" << endl;
    cout << "Enter Serial no.: ";
    cin >> n;
    while (n < '0' || n > '3') 
	{
        cout << "Invalid Enter again: ";
        cin >> n;
    }
    return n;
}
void write1()
{
	ofstream write1("english.txt");
	if(!write1)
	{
		cout << "Error\n";
		return;
	}
	write1 << "Fill in the blanks\n";
	write1 << "1) appl_\na)e a)r c)s d)w\n";
	write1 << "2) man_o\na)t b)l c)g d)p\n";
	write1 << "3) or_nge\na)z b)x c)k d)a\n";
	write1 << "4) c_erry\na)h b)e c)g d)m\n";
	write1 << "5) aprico_\na)t b)s c)v d)n\n";
	write1.close();
}
void write2()
{
	ofstream write2("math.txt");
	if(!write2)
	{
		cout << "Error\n";
		return;
	}
	write2 << "Choose correct answer\n";
	write2 << "1) 2 + 2 = \na)4 b)5 c)9 d)3\n";
	write2 << "2) 6 - 5 = \na)3 b)1 c)5 d)2\n";
	write2 << "3) 12 / 6 = \na)1 b)3 c)2 d)10\n";
	write2 << "4) 13 * 2 = \na)14 b)8 c)46 d)26\n";
	write2 << "5) (3 + 2) - 4 = \na)1 b)43 c)0 d)7\n";
	write2.close();
}
void write3()
{
	ofstream write3("science.txt");
	if(!write3)
	{
		cout << "Error\n";
		return;
	}
	write3 << "1) Which of the following is a fruit?\na)banana b)carrot c)bread d)cheese\n";
	write3 << "2) What is the color of the sky?\na)green b)blue c)red d)orange\n";
	write3 << "3) Which animal lives in water?\na)cat b)fish c)bird d)rabbit\n";
	write3 << "4) Which animal says meow?\na)dog b)cat c)lion d)elephant\n";
	write3 << "5) What do we use to see things?\na)ears b)hands c)eyes d)nose\n";
	write3.close();
}
void read1()
{
	ifstream read1("english.txt");
	if(!read1)
	{
		cout << "Error\n";
		return;
	}
}
void read2()
{
	ifstream read1("math.txt");
	if(!read2)
	{
		cout << "Error\n";
		return;
	}
}
void read3()
{
	ifstream read1("science.txt");
	if(!read3)
	{
		cout << "Error\n";
		return;
	}
}
int main() 
{
    ofstream write_d("Student Accounts.txt");
    if (!write_d) 
	{
        cout << "Error\n";
        return 0;
    }
    else 
	{
        write_f(write_d);
        write_d.close();
    }
    char* id = new char[20];
    char* pass = new char[10];
    bool check = input(id, pass);
    while (!check) 
	{
        check = input(id, pass);
    }
    delete[] id;
    delete[] pass;
    char n;
    if (check) 
	{
        n = display();
    }
    write1();
    write2();
    write3();
    if(n == 1)
    {
    	read1();
	}
    else if(n == 2)
    {
    	read2();
	}
	else
	{
		read3();
	}
    return 0;
}