#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
	vector<vector<pair<int, int> > > edges;

	FILE *f = fopen("input.txt", "r");
	int a,v,i=0;

	while (!feof(f)){
		a = 1;
		vector<pair<int, int> > q;

		edges.push_back(q);

		while (a != 0){
			fscanf(f, "%d %d", &a, &v);
			if (v == 0) break;
			edges[i].push_back(make_pair(a,v));
		}
		i++;
	}
	printf("edges set {");
	for (int i = 0; i < edges.size(); i++)
		printf(" %d ",i+1);
	printf("}\n");
	printf("select edge:\n");
	int x;
	scanf("%d", &x);

	for (int i = 0; i < edges[x - 1].size(); i++)
	{
		printf("%d - %d\n", x, edges[x - 1][i].first);
	}

	return 0;
}
