# add custom variables to this file

# USER_CFLAGS allows to pass custom flags to the compiler
# for example search paths like:
# USER_CFLAGS = -I src/objects

USER_CFLAGS = -I./include -g -static -fno-optimize-sibling-calls -fno-strict-aliasing -DONLINE_JUDGE -D_LINUX -lm -s -x c++ -O2

# USER_LDFLAGS allows to pass custom flags to the linker
# for example libraries like:
# USER_LD_FLAGS = libs/libawesomelib.a

USER_LDFLAGS =

# use this to add system libraries for example:
# USER_LIBS = -lpango
 
USER_LIBS = 

# change this to add different compiler optimizations to your project

USER_COMPILER_OPTIMIZATION = -march=native -mtune=native -Os

EXCLUDE_FROM_SOURCE="bin,.xcodeproj,obj"
