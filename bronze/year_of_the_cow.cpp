#include <bits/stdc++.h>
using namespace std;

int findNthOccurence(string str, char value, int occurence){
    int counter = 0;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == value){
            counter++;
            if (counter == occurence){
                return i;
            }
        }
    }
    return -1;
}

int main() {
    int n; cin >> n;
    
    //holds the clues given
    vector<string> clues(n + 1);
    
    //year difference from bessie
    map<string, int> year_difference;

    //maps the year born for every cow
    map<string, string> year_born;

    //indices of each year in sequence
    map<string, int> year_number;

    vector<string> animals_in_order = {"Ox", "Tiger", "Rabbit", "Dragon",
        "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

    //initialise bessie as the first value which is 0
    year_difference["Bessie"] = 0;
    //set bessie's year born
    year_born["Bessie"] = "Ox";

        //set each year in sequence
    year_number["Ox"] = 0;
        year_number["Tiger"] = 1;
        year_number["Rabbit"] = 2;
        year_number["Dragon"] = 3;
        year_number["Snake"] = 4;
        year_number["Horse"] = 5;
        year_number["Goat"] = 6;
        year_number["Monkey"] = 7;
        year_number["Rooster"] = 8;
        year_number["Dog"] = 9;
        year_number["Pig"] = 10;
        year_number["Rat"] = 11;

    for (int i = 0; i < n + 1; i++)
        getline(cin, clues[i]);

    //loop through all clues
    for (int i = 1; i < n + 1; i++){
        //the name of the year difference cow that we are trying to find
        string name = clues[i].substr(0, clues[i].find(" "));

        //holds 'previous' or 'next'
        string minus_or_plus = clues[i].substr(findNthOccurence(clues[i], ' ', 3) + 1,
            (findNthOccurence(clues[i], ' ', 4) - findNthOccurence(clues[i], ' ', 3) - 1));
        
        //the year animal of the year difference cow that we are trying to find
        string year_animal = clues[i].substr(findNthOccurence(clues[i], ' ', 4) + 1,
            (findNthOccurence(clues[i], ' ', 5) - findNthOccurence(clues[i], ' ', 4) - 1));

        //reference year from another cow
        string from_name = clues[i].substr(findNthOccurence(clues[i], ' ', 7) + 1,
            clues[i].length() - findNthOccurence(clues[i], ' ', 4) - 1);
        
        int index = year_number[year_born[from_name]], counter = 0;
        //cout << animals_in_order[year_number[year_born[from_name]]] << endl;
        //check which way to go
        if (minus_or_plus == "previous"){
            while (true){
                if (animals_in_order[index] == year_animal){
                    //in the same place
                    if (index == year_number[year_born[from_name]]){
                        year_difference[name] = year_difference[from_name] - 12;
                    } else year_difference[name] = year_difference[from_name] - counter;
                    break;
                }
                counter++;
                index--;
                if (index == -1)
                    index = 11;
            }
        } else {
            while (true){
                //in the same place
                if (animals_in_order[index] == year_animal){
                    //in the same place
                    if (index == year_number[year_born[from_name]]){
                        year_difference[name] = year_difference[from_name] + 12;
                    } else year_difference[name] = year_difference[from_name] + counter;
                    break;
                }
                counter++;
                index++;
                if (index == 12)
                    index = 0;
            }
        }
        year_born[name] = year_animal;
    }
    cout << abs(year_difference["Elsie"]) << endl;
}
