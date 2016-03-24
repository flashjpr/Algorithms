/*
 * For N students it is known their name and height (n<=20). The sports teacher
 * wants to sort the students in ascending order of their heights. Write in
 * a file all the ways of sorting the students.
 * Without using sorting algorithms, just using backtracking.*/

#include <iostream>
#include <fstream>

std::ifstream fin ("file.in");
std::ofstream fout ("file.out");

using namespace std;

struct student{
    char name[10];
    float height;
};


// declare a group of max 10 students and the number of students
student group[10];
int studentsNumber;

// method that reads a class of students
void read(student group[], int &studentsNumber) {
    fin >> studentsNumber;

    for (int index = 0; index < studentsNumber; ++index) {
        // read the name and the heights of students
        fin >> group[index].name;
        fin >> group[index].height;
    }
}

int valid(int array[], int counter) {

    int val = 1;

    // check if the current height is < or > than the previous height
    if ((counter > 0) && group[array[counter]].height < group[array[counter]].height) {
        val = 0;
    }

    for (int index = 0; index < counter; ++index) {
        if (array[counter] == array[index]) {
            val = 0;
        }
    }

    return val;
}

void print(int array[], int counter) {

    for (int index = 0; index < counter ; ++index) {
        fout << group[array[index]].name << " " << group[array[index]].height ;
    }
    fout << endl;
}

void backtrack(int studentsNumber) {

    bool other;
    int counter = 0, answer[50];
    answer[counter] = -1;

    while (counter >= 0) {
        do{
            if (counter >= 0) {
                answer[counter]++;
                other = true;
            } else {
                other = false;
            }
        } while (!valid (answer, counter) && other);

        if (other) {

            //print
            if (counter == (studentsNumber - 1) ) {
                print (answer, counter);
            } else {
                counter ++;
                answer[counter] = -1;
            }
        } else {
            counter--;
        }
    } // while
} // backtrack




int main() {

    read(group, studentsNumber);
    backtrack(studentsNumber);

    fin.close();
    fout.close();

    return 0;
}
