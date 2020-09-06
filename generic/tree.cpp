#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <set>
#include <deque> 
#include <string>


using namespace std;


struct Node {
	int pos;
	std::vector<int> connects;
	bool isVisited;
	int level;
	int parent;
};

Node nodes[100010];

int n, a, b, da, db;

//��α���
void makeTree(int node) {
	std::queue<int> q;
	q.push(node);
	nodes[node].isVisited = true;
	nodes[node].level = 0;
	
	int curP, newP;
	while (!q.empty()) {
		curP = q.front();
		q.pop();
		
		for (int i = 0 ; i < nodes[curP].connects.size() ; i++) {
			newP = nodes[curP].connects[i];
			
			if (nodes[newP].isVisited == false) {
				nodes[newP].isVisited = true;
				nodes[newP].level = nodes[curP].level + 1;
				nodes[newP].parent = curP;
				q.push(newP);
			}
		}
	}
}

//����������ľ��룬���в�α��������ϵ�LCA 
int calcDistAB() {
	int curA = a;
	int curB = b;
	int dist = 0;
	while (nodes[curA].level != nodes[curB].level) {
		if (nodes[curA].level > nodes[curB].level) {
			dist++;
			curA = nodes[curA].parent;
		} else {
			dist++;
			curB = nodes[curB].parent;
		}
	}
	
	while (curA != curB) {
		dist = dist + 2;
		curA = nodes[curA].parent;
		curB = nodes[curB].parent;	//һ���ܵ�һ�� 
	}
	
	return dist;
}

//������ֱ��������DFS����ʱ�Ѿ�����һ��BFS���Բ���Ҫ�� 
int calcDia() {
	//����DFS
	
	int maxLevel = -1;
	int maxP;
	for (int i = 1 ; i <= n ; i++) {
		if (nodes[i].level > maxLevel) {
			maxP = i;
			maxLevel = nodes[i].level;
		}
		
		nodes[i].isVisited = false;
		nodes[i].level = -1;
		nodes[i].parent = -1;
	}
	
	makeTree(maxP);
	
	int maxDist = -1;
	for (int i = 1 ; i <= n ; i++) {
		if (nodes[i].level > maxDist) {
			maxDist = nodes[i].level;
		}
	}
	
	return maxDist;
}


