cmake_minimum_required(VERSION 3.24)
project(ASD_rgr)

set(CMAKE_CXX_STANDARD 17)

add_executable(ASD_rgr src/main.cpp src/SimpleGraph.cpp src/SimpleGraph.h src/elements/Edge.cpp src/elements/Edge.h src/elements/Vertex.cpp src/elements/Vertex.h src/iterators/EdgeIterator.cpp src/iterators/EdgeIterator.h src/iterators/VertexIterator.cpp src/iterators/VertexIterator.h src/forms/LGraph.cpp src/forms/LGraph.h src/forms/MGraph.cpp src/forms/MGraph.h src/forms/GraphForm.cpp src/forms/GraphForm.h src/iterators/AdjEdgeIterator.cpp src/iterators/AdjEdgeIterator.h)
