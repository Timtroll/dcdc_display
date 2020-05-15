all:
	{ \
	cd ../; \
	git submodule init; \
	git submodule update; \
	cd tdd_creator/; \
	git submodule init; \
	git submodule update; \
	cd ../software/; \
	}
	./delete_comment ./inc/paper_screen/paper_screen_internal.h
	make -f MakefileUnity.mk
	./insert_comment ./inc/paper_screen/paper_screen_internal.h
	

clean:
	make -f MakefileUnity.mk clean


