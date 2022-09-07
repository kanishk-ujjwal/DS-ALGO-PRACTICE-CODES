#include <bits/stdc++.h>

using namespace std;

string INPUT_FILE = "a.txt";
string OUTPUT_FILE = "a.out";

ofstream fout (OUTPUT_FILE);
ifstream fin (INPUT_FILE);

class Contributor{
    public:
    string name;
    int numSkills;
    map<string, int> skills;

    public:
    void readData(){
        fin >> name >> numSkills;
        for(int i = 0; i < numSkills; ++i){
            string skill; int level;
            fin >> skill >> level;
            skills.insert({skill, level});
        }

        return;
    }

    void outputData(){
        fout << name << " " <<  numSkills << "\n";
        for(auto skill: skills){
            fout << skill.first << " " << skill.second << "\n";
        }

        return;
    }

};

class Project{
    public:
    string name;
    int daysToComplete;
    int score;
    int bestBefore;
    int roles;
    map<string, int> reqSkills;

    public:
    void readData(){
        fin >> name >> daysToComplete >> score >> bestBefore >> roles;
        for(int i = 0; i < roles; ++i){
            string skill; int level;
            fin >> skill >> level;
            reqSkills.insert({skill, level});
        }

        return;
    }

};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int CONTRIBUTORS, PROJECTS;

    fout << CONTRIBUTORS << " " << PROJECTS << "\n";

    vector<Contributor> contributorList(CONTRIBUTORS);
    for(int i = 0; i < CONTRIBUTORS; ++i){
        contributorList[i].readData();
    }
    vector<Project> projectList(PROJECTS);
    for(int i = 0; i < PROJECTS; ++i){
        projectList[i].readData();
    }




    return 0;
}
