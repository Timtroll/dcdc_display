all:
	{ \
	cd ../; \
	git submodule init; \
	git submodule update; \
	cd tdd_creator/; \
	git submodule init; \
	git submodule update; \
	cd ../dcdc/; \
	}
	make -f MakefileUnity.mk

clean:
	make -f MakefileUnity.mk clean


