#include <vector>
#include <nanobind/nanobind.h>

class UnionFind
{
    public:
                UnionFind(size_t n):
                    parent(n, -1), rank(n, 1)           {}

        long    find(long v)
        {
            long cur = v;
            std::vector<long> trail;
            while(parent[cur] != -1)
            {
                trail.push_back(cur);
                cur = parent[cur];
            }

            // path compression
            for (auto u : trail)
                parent[u] = cur;

            return cur;
        }

        void    merge_root(long u, long v)
        {
            if (rank[u] < rank[v])
            {
                parent[u] = v;
                rank[v] += rank[u];
            } else
            {
                parent[v] = u;
                rank[u] += rank[v];
            }
        }

        void    merge(long u, long v)
        {
            merge_root(find(u), find(v));
        }


    private:
        std::vector<long> parent;
        std::vector<long> rank;
};

namespace nb = nanobind;

NB_MODULE(union_find, m) {
    nb::class_<UnionFind>(m, "UnionFind")
        .def(nb::init<size_t>())
        .def("find",        &UnionFind::find)
        .def("union",       &UnionFind::merge)
        .def("union_root",  &UnionFind::merge_root)
    ;
}
