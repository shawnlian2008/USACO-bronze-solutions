#include <bits/stdc++.h>
using namespace std;

struct Time { // Time object
    int start, end, id;
    bool operator<(const Time &y) { return y.start > start; }
};

int main(){
    int n; cin >> n;
    vector<Time> times(n); // Holds the times in given order
    for (int i = 0; i < n; i++){
        cin >> times[i].start >> times[i].end;
        times[i].id = i; // id is the order that they give us
    }

    sort(times.begin(), times.end()); // Id's are already assigned and preserved for later use
    
    vector<int> room_assignment(n, -1); // Room assignments in order based on id
    multiset<pair<int, int>> occupied; // {end time, room assignment}
    int room_count = 1; // What room is the largest room assignment
    for (int i = 0; i < n; i++){ // Go through all times of the customers by sorted arrival time
        if (occupied.size() == 0){ // Nothing in the multiset yet
            occupied.insert({times[i].end, room_count}); // Add first person to rooms
            room_assignment[times[i].id] = room_count; // Set room number for person
            room_count++; // Add to the next unoccupied room, the room next to this person's
            continue;
        }

        pair<int, int> earliest = *occupied.begin(); // Earliest ending time (First room to be available)
        if (times[i].start > earliest.first){ // The earliest possible room to be available is already available
            room_assignment[times[i].id] = earliest.second; // Set room number for person
            occupied.erase(occupied.find(earliest)); // Remove the person who was previously in the room
            occupied.insert({times[i].end, earliest.second}); // Add the new person to the room
        } else { // No rooms are available just yet
            room_assignment[times[i].id] = room_count; // Set room number for person
            occupied.insert({times[i].end, room_count}); // Add this person to the room
            room_count++; // Increase room number, since we open a new room for the person since there are no more rooms available.
        }
    }

    cout << room_count - 1 << endl; // Number of rooms allocated, subtract 1 because it already starts out as 1 (there is no 0 room number)
    for (int i = 0; i < n; i++) 
        cout << room_assignment[i] << " ";
}
