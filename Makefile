# Название исполняемого файла
TARGET = build/main.exe

# Компилятор
CXX = g++

# Папки с заголовочными файлами
INCLUDE_DIRS = headers\
				headers/table

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++11 -g $(addprefix -I, $(INCLUDE_DIRS)) -fdebug-prefix-map=$(CURDIR)=.

# Исходные файлы
SRCS = sources/main.cpp \
       sources/Impl.cpp \
       sources/DNF.cpp \
       sources/Cover_table.cpp \
	   sources/Automat.cpp \
	   sources/table/*.cpp 

# Объектные файлы (будут размещены в папке build)
OBJS = $(patsubst sources/%.cpp sources/table/%.cpp, build/%.o, $(SRCS))

# Правило по умолчанию — сборка проекта
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	@if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для сборки объектных файлов
build/%.o: sources/%.cpp
	@if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки (удаление объектных файлов и исполняемого файла)
clean:
	rm -f build/*.o build/main.exe

# Правило для повторной сборки всего проекта
rebuild: clean all
