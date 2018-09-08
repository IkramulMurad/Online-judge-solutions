#include <bits/stdc++.h>
using namespace std;

struct Edge
{
	int v, flow, cap, index;
	Edge(){}
	Edge(int v, int flow, int cap, int index) : v(v), flow(flow), cap(cap), index(index) {}
};

const int mx = 205;
const int inf = 1e9;
vector <vector <Edge> > g(mx);
int label[mx];
int start[mx];

void addEdge(int u, int v, int cap, vector <vector <Edge> > &g){
	Edge a(v, 0, cap, g[v].size());
	Edge b(u, 0, 0, g[u].size());       //reverse edge

	g[u].push_back(a);
	g[v].push_back(b);
}

int in(int i){
    return 2 * i;
}
 
int out(int i){
    return 2 * i + 1;
}

bool bfs(int s, int t){
	memset(label, -1, sizeof(label));
	queue <int> q;
	q.push(s);

	label[s] = 0;
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); ++i){
			Edge &edge = g[u][i];
			int &v = edge.v;
			if (label[v] == -1 && edge.flow < edge.cap){
				q.push(v);
				label[v] = label[u] + 1;
				if (v == t) return true;
			}
		}
	}
	return false;
}

int dfs(int u, int t, int prevFlow){
	if (u == t) return prevFlow;

	for (int &i = start[u]; i < g[u].size(); ++i){
		Edge &edge = g[u][i];
		int &v = edge.v;
		if (label[v] == label[u] + 1 && edge.flow < edge.cap){
			int minFlowTillNow = min(prevFlow, edge.cap - edge.flow);
			int minPathFlow = dfs(v, t, minFlowTillNow);

			if (minPathFlow > 0){
				edge.flow += minPathFlow;
				g[v][edge.index].flow -= minPathFlow;
				return minPathFlow;
			}
		}
	}
	return 0;
}

int dinic(int s, int t){
	if (s == t) return 0;

	int maxFlow = 0;
	while (bfs(s, t)){
		memset(start, 0, sizeof(start));
		while (int flow = dfs(s, t, inf)){
			maxFlow += flow;
		}
	}
	return maxFlow;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    int tc;
    scanf("%d", &tc);
 
    for(int t = 1; t <= tc; ++t){
        int ice;
        double d;
        scanf("%d %lf", &ice, &d);
 
        int x[mx], y[mx], n[mx], m[mx], total = 0;
        vector <vector <Edge> > graph(mx);
 
        for(int i = 0; i < ice; ++i){
            scanf("%d %d %d %d", &x[i], &y[i], &n[i], &m[i]);
            total += n[i];
            addEdge(in(i), out(i), m[i], graph);
        }
 
        for(int i = 0; i < ice; ++i){
            for(int j = i + 1; j < ice; ++j){
                double dist = hypot(x[i] - x[j], y[i] - y[j]);
                if(dist <= d){
                    addEdge(out(i), in(j), m[i], graph);
                    addEdge(out(j), in(i), m[j], graph);
                }
            }
        }
 
        vector <int> v;
        for(int i = 0; i < ice; ++i){
            //copy whole graph
            g = graph;
 
            //connect source to nodes
            for(int j = 0; j < ice; ++j){
                if(n[j] and j != i){
                    addEdge(2 * ice, in(j), n[j], g);
                }
            }
 
            int flow = dinic(2 * ice, in(i));
            if(flow == total - n[i]){
                v.push_back(i);
            }
        }
 
        printf("Case %d:", t);
        if(v.size() == 0){
            printf(" -1");
        }
        else{
            for(int i = 0; i < v.size(); ++i){
                printf(" %d", v[i]);
            }
        }
        printf("\n");
    }
 
    return 0;
}
