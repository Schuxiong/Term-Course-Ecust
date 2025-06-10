#include <iostream>
#include <algorithm>
using namespace std;
int x, y, x1, y1, n;
char face[51];
unsigned long long ans = 0x3f;
short dx[5] = {1, 0, -1, 0, 0}, dy[5] = {0, 1, 0, -1, 0}; 
 
void dfs(unsigned long long dep, int xx, int yy){
	if(dep > n) return ;
	if(dep > ans) return;
	if(xx == x1 && yy == y1){
		ans = min(ans, dep);
		return;
	}
	if(face[dep] == 'E')
		dfs(dep+1, xx+1, yy);
	else if(face[dep] == 'S')
		dfs(dep+1, xx, yy-1);
	else if(face[dep] == 'N')
		dfs(dep+1, xx, yy+1);
	else if(face[dep] == 'W')
		dfs(dep+1, xx-1, yy);
	dfs(dep+1, xx, yy);
} 
 
int main(){
	cin >> x >> y >> x1 >> y1 >> n;
	for(int i=0; i<n; i++)
		cin >> face[i];
	dfs(0, x, y);
	if(ans == 0x3f) cout << "-1" << endl;
	else cout << abs(x1 - x) + abs(y1-y) << endl;
	return 0;
}


