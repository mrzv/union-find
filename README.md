# Simple Union-Find

## Install

```
pip install git+https://github.com/mrzv/union-find
```

## Run

```
import union_find

uf = union_find.UnionFind(10)       # 10 vertices total {0, ..., 9}

print(uf.find(4), uf.find(5))
# 4 5

uf.union(4,5)

print(uf.find(4), uf.find(5))
# 4 4
```
