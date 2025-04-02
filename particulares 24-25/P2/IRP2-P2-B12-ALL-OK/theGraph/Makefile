OPTS=--std=c++0x -g

# Tree tests
#TT = t1 t2 t3 t4 t5 t6  t7 t8 t9 t16 t19
# Graph tests
TG = t10 t11 t12 t13 t14 t15 t17 t18


TESTS = $(TG)

all: $(TESTS)

#$(TT):
#	g++ $(OPTS) $@.cc tree.cc -o $@

$(TG):
	g++ $(OPTS) $@.cc graph.cc -o $@

clean:
	rm -f $(TESTS) *.o *~ a.out

.PHONY: $(TESTS)
