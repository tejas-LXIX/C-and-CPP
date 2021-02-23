#include<iostream>
using namespace std;

class Student
{
    private:
        int scores[5]; //Student[n] is an array of 'n' Student objects. Each object has 
        //an array of length 5 which stores the scores of that particular student. less complicated than using 2d array for this task.
        int total=0;
    public:
        void input()
        {
            for(int i=0;i<5;i++)
            {
                cin>>scores[i];
            }
        }
        int calculateTotalScore()
        {
            for(int i=0;i<5;i++)
            {
                total+=scores[i];
            }
            return total;
        }
};
// Write your Student class here

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
