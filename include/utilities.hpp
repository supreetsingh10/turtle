#pragma once
#define SAFE_RELEASE_VECTOR(vec) for(auto e : vec) delete e
#define POPULATE_MAP(m, start, end, type) for(char i = start; i <= end; i++) { m[i] = type; }
