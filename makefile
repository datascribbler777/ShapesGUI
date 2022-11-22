CXX = g++
BLDDIR = bin
SRCDIR = src
INCDIR = inc
OBJDIR = obj
TESTDIR = tests
CPPFLAGS = -Iinc -Wall -O1
LDFLAGS = -L lib
LXXFLAGS = -lgtest -lpthread -lraylib -lopengl32 -lgdi32 -lwinmm
GTEST = D:\Pinky\Workspace\C++\Google Test\googletest-release-1.11.0\lib\libgtest.a
RAYLIBS = \lib\libraylib.a

.PHONY: all
all: $(BLDDIR)/.dirstamp $(OBJDIR)/.dirstamp $(BLDDIR)/shapes

$(BLDDIR)/.dirstamp:
	mkdir -p $(BLDDIR)
	touch $(BLDDIR)/.dirstamp
	
$(OBJDIR)/.dirstamp:
	mkdir -p $(OBJDIR)
	touch $(OBJDIR)/.dirstamp
	
$(BLDDIR)/shapes: $(OBJDIR)/shapes.o $(RAYLIBS)
	$(CXX) $(LXXFLAGS) $^ -o $@
	
$(OBJDIR)/shapes.o: $(SRCDIR)/shapes.cpp
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm $(BLDDIR)/*
	rm $(OBJDIR)/*.*
