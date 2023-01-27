/* CIS 142 Introduction to C++ Fall 2022
programming Assignment #12
Author: Jonathan Lewis
Date Due: 2022/12/15

This program follows the specfications found in the program 12 document.*/

#include <iostream>
#include <algorithm>
using namespace std;


//There will be a function for various turn. Each function will take the array as an argument. Some turns will also take the turn number as an argument.  
int iteratori(int primeset[1][5]);
int onesix(int set[5], int turn);
int seven(int set[5], int turn);
int nine(int set[5]);
int ten(int set[5]);
int eleven(int set[5]);
int twelve(int set[5]);
int thriteen(int set[5]);

//main function that can call a test set. 
int main(){
    int test_array[13][5] = {{1,1,1,1,1}, {2,2,2,2,2}, {3,3,3,3,3}, {4,4,4,4,4}, {5,5,5,5,5}, {6,6,6,6,6}, {6,6,6,6,6}, {6,6,6,6,6},{1,1,2,2,2}, {1,2,3,4,5}, {1,2,3,4,5}, {1,1,1,1,1}, {6,6,6,6,6}};
    //iteratori(test_array);
}

//This function will need a counter so it knows which function to call using a switch statment. It will be a for loop and will iterate over the entrie set of sets. 
int iteratori(int primeset[1][5]){
    //variable to keep track of turn and control switch.
    int turn = 1;
    //total points scored.
    int total = 0;
    //temporaty variable points that stores the return value of each function called.
    int points = 0;
    //The loop that iterates over each array in the array.
    for (int i = 0; i < 13; i++){
        switch(turn){
            case 1:
            points = onesix(primeset[i], turn);
            total += points; // 5 Total 5
            break;
            case 2:
            points = onesix(primeset[i], turn);
            total += points; //10 total 15
            break;
            case 3:
            points = onesix(primeset[i], turn);
            total += points; //15 total 30
            break;
            case 4:
            points = onesix(primeset[i], turn);
            total += points; // 20 total 50
            break;
            case 5:
            points = onesix(primeset[i], turn);
            total += points; //25 total 75
            break;
            case 6:
            points = onesix(primeset[i], turn);
            total += points; // 30 total 105
            break;
            case 7:
            points = seven(primeset[i], turn);
            total += points; // 30 total 135
            break;
            case 8:
            points = seven(primeset[i], turn);
            total += points; //30 total 165
            break;
            case 9:
            points = nine(primeset[i]);
            total += points; //25 total 190
            break;
            case 10:
            points = ten(primeset[i]);
            total += points; //30 total 220
            break;
            case 11:
            points = eleven(primeset[i]);
            total += points; //40 total 260
            break;
            case 12:
            points = twelve(primeset[i]);
            total += points; //50 total 310
            break;
            case 13:
            points = thriteen(primeset[i]);
            total += points;//30 total 340
            break;
        }
    turn += 1;
    }
return total;
}

//For turns 1-6. If the dice eqauls the turn number, you get the sum of all the dice that apply.
int onesix(int set[5], int turn){
int points = 0;
 for (int i = 0; i < 5; i++){
    //The logic checks to see if the dice is equal to the turn number. If so, adds to the points.
    if (set[i] == turn){
    points += turn;
    }
    else{
        continue;
    }
 }
 return points;
}
// 1,2,2,2,6
//for turn seven and eight: three of a kind. If there are 3 dice that show the same number, sum all dice. works
int seven(int set[5], int turn){
    sort(set, set + 5);
    int points = 0;
    int index = 0;
    int count = 1;
    //This logic checks to see if the current index is equal to the previous index. If so, it adds one to the count.
    for (int i = 0; i < 5; i++){
        if (set[i] == index){
            count += 1;
        }
        //If the count doesn't equal the turn number -4 (3 or 4 depending on the turn.) It knows to keep going.
        else if(count != turn - 4){
        index = set[i];
        count = 1;
        }
        //If count is greater then turn minus 4, it knows to keep going.
        else if(count > turn - 4){
        continue;
        }
        //it will add to points the dice number.
        points += set[i];
        }
    //if the count is greater then turn -4, then you get the points. Else, you don't get the points. 
    if (count >= turn - 4){
        return points;
    }
    else{
        return 0;
    }
}

//For turn nine: If there is a pair of dice, and a tri of another dice, you get 25 points. -works
int nine(int set[5]){
    //Sorting the numbers in the array so that they are grouped together if the match.
    sort(set, set + 5);
    //This variable keeps track of the prior number.
    int index = 0;
    //This is the count of matching numbers
    int counta = 1;
    //If there are 3 numbers that match, the middle indext will always contain the number with 3.
    int number = set[2];
    //The number of points to be returned.
    int points = 0;
    //Iterates over each number in the array.
    for (int i = 0; i < 5; i++){
        //This if checks to see if the current number matches the prior number. It will increase the count by one if it does.
        if (set[i] == index){
            counta += 1;
        }
        //This checks to see if count is not 3. The first if statments catches matches, and this one makes sure not to reset the count if it is already 3.
        else if(counta != 3){
        index = set[i];
        counta = 1;
        }
        //This is to make sure if there are 4+ matches, that the count doesn't get reset.
        else if(counta > 3){
        continue;
        }
     }
    //This logic takes the information and runs logic on it.
    //If the count is 5, we know that there is a 3 matching numbers, and a pair of matching numbers.
     if(counta == 5){
        points = 25;
     }
     //If the count is 4 we know that there are 4 matching numbers, but 1 odd man out.
     else if(counta == 4){
        points = 0;
     }
     //If there are 3 matching numbers, but they are the 3 middle numbers, we know that number 1 and nbumber 5 are different because they are soreted.
     else if((set[1] == number) && (set[4] == number)){
        points = 0;
     }
     //If the count is 3, then we need to look further into the numbers.
     else if(counta == 3){
        //This block checks the index of the matching numbers.
        //If the second numbers is the number that has 3 pairs, this logic checks to see if the last 2 numbers match.
        if (set[1] == number){
            if (set[3] == set[4]){
                points = 25;
            }
            else{
                points = 0;
            }
        }
        //If the forth numbers is the number that has 3 pairs, this logic checks to see if the first 2 numbers match.
        else if(set[3] == number){
            if (set[0]== set[1]){
                points = 25;
            }
            else{
                points = 0;
            }
        }
        else{
            points = 0;
        }
     }
     else {
        points = 0;
     }
     //returns points. 
    return points;
}

//turn eleven: If there is a run of 5 dice, you get 40 points. Else, 0.
int eleven(int set[5]){
    sort(set, set + 5);
    int points = 0;
    //bool varaible to see if it is a run of 5.
    bool t_f = true;
    //the two possiblilities. 
    int one_five[5] = {1,2,3,4,5};
    int two_six[5] = {2,3,4,5,6};
    //This logic splits up the numbers into 3 possiblities. If index is 1, 2, or else. If not one or two, then return 0 points.
    if(set[0] == 1){
        //iterates over the set and makes sure that each index matches the coorisponding index.
        for (int i = 0; i < 5; i++){
            if (set[i] == one_five[i] && t_f == true){
            }
            else{
                points = 0;
                t_f = false;
                break;
            }
        }
    }
    //dito
    else if(set[0] == 2){
        for (int i = 0; i < 5; i++){
            if (set[i] == two_six[i] && t_f == true){
            }
            else{
                points = 0;
                t_f = false;
                break;
            }
        }
    }
    else{
        points = 0;
        }
    //if the boolian is still true, then it is a run of 5
    if (t_f == true){
        points = 40;
    }
    else{
        points = 0;
    }

    return points;
}

//For turn ten, there must be a run of 4 numbers. If so, 30 points.
int ten(int set[5]){
    sort(set, set + 5);
    int unique[5] = {0,0,0,0,0};
    int last_number = 0;
    int points = 0;
    int count = 1;
    int count2 = 1;
    //code check to see if there are any repeated numbers. If 2 or less, contiune, else 0 points
    for (int i = 0; i < 4; i++){
        if(set[i] == set[i+1]){
            count += 1;
        }
        else if (count == 3) {
            break;
        }
        else {
            continue;
        }
    }
    if (count >= 3){
        points = 0;
    }
    //Code that pulls unique numbers and adds them to an array.
    else {
        //This logic Checks to see if the number is unique. If so, it changes the unique array to match the coorisponding numbers.
        for (int i = 0; i < 5; i++){
            //this piece of logic tells it to skipp number that are the same
            if(set[i] == last_number){
                last_number = set[i];
                continue;
            }
            //this piece of logic tells it to add numbers that are unique.
            else {
                last_number = set[i];
                unique[i] = set[i];
            }
        }
        //Code that  organizes the numbers and checks to see if they step by one. 
        sort(unique, unique + 5);
        //This is where we check if its 0 so that we can start at the right index.
        for (int i = 0; i < 4; i++){
            if(unique[i] == 0){
                continue;
            }
            //if the index isn't 0, we can run logic on it to see if it is a run.
            else if(unique[i] != 0){
                //this sets the last number to the current index so that we can check it.
                last_number = unique[i];
                //If the current index + 1 is equal to the next index, we know the number is consecutive and we can add +1 to the count.
                if (last_number + 1 == unique[i+1]){
                    count2 += 1;
                }
                else {
                    count2 = 1;
                }
            }
        }
        //if count is greater then or = to four, we have a run!, then 30 points, else no. 
        if (count2 >= 4){
            points = 30;
        }
        else{
            points = 0;
        }
    }
return points;
}

//If all 5 dice are the same, you get 50 points.
int twelve(int set[5]){
    int count = 1;
    int points = 0;
    //THis logic will count the dice that are the same.
    for (int i = 0; i < 4; i++){
        if(set[i] == set[i+1]){
            count += 1;
        }
        else{
            break;
        }
    }
    //If count is 5, then you get 50 points.
    if (count == 5){
        points = 50;
    }
    else{
        points = 0;
    }
    return points;
}

//Simply adds the numbers. 
int thriteen(int set[5]){
    int points = 0;
    for (int i = 0; i < 5; i++){
        points += set[i];
    }
    return points;
}