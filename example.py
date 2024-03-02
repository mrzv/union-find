import union_find

uf = union_find.UnionFind(10)

print(uf.find(4), uf.find(5))
uf.union(4,5)
print(uf.find(4), uf.find(5))
