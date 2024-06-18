#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int totalTime = 0;
int currentTime = 0;
void printQueue(queue<pair<pair<int, int>,int>> q) {
    cout << "Queue: ";
    while (!q.empty()) {
        cout << "(" << q.front().first.first << ", " << q.front().first.second <<", " << q.front().second << ") ";
        q.pop();
    }
    cout << endl;
}

void bfs(vector<vector<int>>& graph, pair<int, int> start, vector<vector<bool>>& visited, double moveTime) {
    int rows = graph.size();
    int cols = graph[0].size();

    int dx[] = {0, 0, -1, 1,1,-1,1,-1};
    int dy[] = {-1, 1, 0, 0,1,-1,-1,1};

    queue<pair<pair<int, int>,int>> q;
    q.push({start,0});
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        // printQueue(q);
        pair<pair<int, int>,int> current = q.front();
        q.pop();
        if(currentTime >= totalTime){
            totalTime = currentTime;
        }
        currentTime = current.second;

        
        

        for (int i = 0; i < 8; ++i) {
            int nx = current.first.first + dx[i];
            int ny = current.first.second + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && graph[nx][ny] == 1 && !visited[nx][ny]) {
                q.push({{nx, ny},currentTime + 1});
                visited[nx][ny] = true;
            
            }
        }
    }
}

int main() {
    vector<vector<int>> C102 ;
    C102 = {    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
                {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
                {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
                {0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
                {0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1,1,1,1,1},
                };

    int rows = C102.size();
    int cols = C102[0].size();
    cout << rows << cols << endl;

    double moveTime = 1.0;  

    cout << "Block 1 critical points: "<< endl;
    vector <pair<int,int>> pointsFirstBlock;
    pointsFirstBlock.push_back({0,13});
    pointsFirstBlock.push_back({0,21});
    pointsFirstBlock.push_back({6,7});
    pointsFirstBlock.push_back({6,19});
    pointsFirstBlock.push_back({2,14});
    
    
    for(int i = 0; i < 5; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
            pair<int, int> startingPoint = pointsFirstBlock[i];
            bfs(C102, startingPoint, visited, moveTime);
            if(i == 4){
                cout <<"Center";
            }
            else{
                cout<< "Corner " << i + 1;
            }
            cout << ": (" << startingPoint.first << ", " << startingPoint.second << ") - Time taken: " << totalTime << " seconds." << endl;
            currentTime = 0;
            totalTime = 0;
    }   
    cout << endl;
    cout << "Block 2 critical points: "<< endl;
    vector <pair<int,int>> pointsSecondBlock;
    pointsSecondBlock.push_back({0,24});
    pointsSecondBlock.push_back({0,34});
    pointsSecondBlock.push_back({6,22});
    pointsSecondBlock.push_back({6,36});
    pointsSecondBlock.push_back({4,29});
    
    
    for(int i = 0; i < 5; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
            pair<int, int> startingPoint = pointsSecondBlock[i];
            bfs(C102, startingPoint, visited, moveTime);
            if(i == 4){
                cout <<"Center";
            }
            else{
                cout<< "Corner " << i + 1;
            }
            cout << ": (" << startingPoint.first << ", " << startingPoint.second << ") - Time taken: " << totalTime << " seconds." << endl;
            currentTime = 0;
            totalTime = 0;
    }   
    cout << endl;
    cout << "Block 3 critical points: "<< endl;
    vector <pair<int,int>> pointsThirdBlock;
    pointsThirdBlock.push_back({0,37});
    pointsThirdBlock.push_back({0,45});
    pointsThirdBlock.push_back({6,39});
    pointsThirdBlock.push_back({6,51});
    pointsThirdBlock.push_back({2,44});
    
    
    for(int i = 0; i < 5; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
            pair<int, int> startingPoint = pointsThirdBlock[i];
            bfs(C102, startingPoint, visited, moveTime);
            if(i == 4){
                cout <<"Center";
            }
            else{
                cout<< "Corner " << i + 1;
            }
            cout << ": (" << startingPoint.first << ", " << startingPoint.second << ") - Time taken: " << totalTime << " seconds." << endl;
            currentTime = 0;
            totalTime = 0;
    }   

    cout << endl;
    cout << "Block 4 critical points: "<< endl;
    vector <pair<int,int>> pointsFourthBlock;
    pointsFourthBlock.push_back({10,2});
    pointsFourthBlock.push_back({10,13});
    pointsFourthBlock.push_back({15,0});
    pointsFourthBlock.push_back({15,13});
    pointsFourthBlock.push_back({12,6});
    
    
    for(int i = 0; i < 5; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
            pair<int, int> startingPoint = pointsFourthBlock[i];
            bfs(C102, startingPoint, visited, moveTime);
            if(i == 4){
                cout <<"Center";
            }
            else{
                cout<< "Corner " << i + 1;
            }
            cout << ": (" << startingPoint.first << ", " << startingPoint.second << ") - Time taken: " << totalTime << " seconds." << endl;
            currentTime = 0;
            totalTime = 0;
    }   

    cout << endl;
    cout << "Block 5 critical points: "<< endl;
    vector <pair<int,int>> pointsFifthBlock;
    pointsFifthBlock.push_back({10,19});
    pointsFifthBlock.push_back({10,27});
    pointsFifthBlock.push_back({15,16});
    pointsFifthBlock.push_back({15,27});
    pointsFifthBlock.push_back({12,21});
    
    
    for(int i = 0; i < 5; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
            pair<int, int> startingPoint = pointsFifthBlock[i];
            bfs(C102, startingPoint, visited, moveTime);
            if(i == 4){
                cout <<"Center";
            }
            else{
                cout<< "Corner " << i + 1;
            }
            cout << ": (" << startingPoint.first << ", " << startingPoint.second << ") - Time taken: " << totalTime << " seconds." << endl;
            currentTime = 0;
            totalTime = 0;
    }   

    cout << endl;
    cout << "Block 6 critical points: "<< endl;
    vector <pair<int,int>> pointsSixthBlock;
    pointsSixthBlock.push_back({10,30});
    pointsSixthBlock.push_back({10,38});
    pointsSixthBlock.push_back({14,30});
    pointsSixthBlock.push_back({14,41});
    pointsSixthBlock.push_back({12,35});
    
    
    for(int i = 0; i < 5; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
            pair<int, int> startingPoint = pointsSixthBlock[i];
            bfs(C102, startingPoint, visited, moveTime);
            if(i == 4){
                cout <<"Center";
            }
            else{
                cout<< "Corner " << i + 1;
            }
            cout << ": (" << startingPoint.first << ", " << startingPoint.second << ") - Time taken: " << totalTime << " seconds." << endl;
            currentTime = 0;
            totalTime = 0;
    }   

    cout << endl;
    cout << "Block 7 critical points: "<< endl;
    vector <pair<int,int>> pointsSeventhBlock;
    pointsSeventhBlock.push_back({10,48});
    pointsSeventhBlock.push_back({10,55});
    pointsSeventhBlock.push_back({15,45});
    pointsSeventhBlock.push_back({15,57});
    pointsSeventhBlock.push_back({13,50});
    
    
    for(int i = 0; i < 5; i++){
            vector<vector<bool>> visited(rows, vector<bool>(cols, false)); 
            pair<int, int> startingPoint = pointsSeventhBlock[i];
            bfs(C102, startingPoint, visited, moveTime);
            if(i == 4){
                cout <<"Center";
            }
            else{
                cout<< "Corner " << i + 1;
            }
            cout << ": (" << startingPoint.first << ", " << startingPoint.second << ") - Time taken: " << totalTime << " seconds." << endl;
            currentTime = 0;
            totalTime = 0;
    }   

    return 0;
}