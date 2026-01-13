class DisjointSet {
public:
    vector<int> parent, size, rank;

    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void UnionByRank(int u, int v) {
        int ulpu = findUPar(u);
        int ulpv = findUPar(v);
        if(ulpu == ulpv) return;

        if(rank[ulpu] < rank[ulpv]) {
            parent[ulpu] = ulpv;
        }
        else if(rank[ulpv] < rank[ulpu]) {
            parent[ulpv] = ulpu;
        }
        else {
            parent[ulpv] = ulpu;
            rank[ulpu]++;
        }
    }

    void UnionBySize(int u, int v) {
        int ulpu = findUPar(u);
        int ulpv = findUPar(v);
        if(ulpu == ulpv) return;

        if(size[ulpu] < size[ulpv]) {
            parent[ulpu] = ulpv;
            size[ulpv] += size[ulpu];
        }
        else {
            parent[ulpv] = ulpu;
            size[ulpu] += size[ulpv];
        }
    }
};

class Solution {
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        // Step 1: Union adjacent 1s
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;

                for(int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        ds.UnionBySize(row * n + col, nr * n + nc);
                    }
                }
            }
        }

        // Step 2: Try flipping each 0
        int mx = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) continue;

                set<int> components;
                for(int i = 0; i < 4; i++) {
                    int nr = row + dr[i];
                    int nc = col + dc[i];
                    if(isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        components.insert(ds.findUPar(nr * n + nc));
                    }
                }

                int sizeTotal = 0;
                for(int comp : components) {
                    sizeTotal += ds.size[comp];
                }

                mx = max(mx, sizeTotal + 1);
            }
        }

        // Step 3: If no zero exists
        for(int cell = 0; cell < n * n; cell++) {
            mx = max(mx, ds.size[ds.findUPar(cell)]);
        }

        return mx;
    }
};
