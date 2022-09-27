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

//层次遍历
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

//求树上两点的距离，在有层次遍历基础上的LCA 
int calcDistAB(int a, int b) {
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
		curB = nodes[curB].parent;	//一定能到一起 
	}
	
	return dist;
}

//求树的直径，两次DFS，此时已经做过一次BFS所以不需要了 
int calcDia() {
	//两次DFS
	
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

struct Group {
	int pos;
	int level;
};
Group groups[200010];

bool compareLevel(const Group &a, const Group &b) {
	return a.level > b.level;
}

bool comparePos(const Group &a, const Group &b) {
	return a.pos < b.pos;
}

void findSub() {
	for (int i = 1 ; i <= n ; i++) {
		groups[i].pos = nodes[i].pos;
		groups[i].level = nodes[i].level;
	}
	
	sort(groups + 1, groups + n + 1, compareLevel);
	
	for (int i = 1 ; i <= n ; i++) {
		int realPos = groups[i].pos;
		for (int j = 0 ; j < nodes[realPos].connects.size() ; j++) {
			int pPos = nodes[realPos].connects[j];
			if (pPos == nodes[realPos].parent)
				continue;
			
			nodes[realPos].totalCount = nodes[realPos].totalCount + nodes[pPos].totalCount;
		}
	}
}

