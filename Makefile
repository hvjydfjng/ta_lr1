# Название исполняемого файла
TARGET = build/main.exe

# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -Wall -Wextra -std=c++11 -g -fdebug-prefix-map=$(CURDIR)=.

# Исходные файлы
SRCS = main.cpp\
Impl.cpp\
DNF.cpp\
Cover_table.cpp

# Объектные файлы (будут размещены в папке build)
OBJS = $(addprefix build/, $(SRCS:.cpp=.o))

# Правило по умолчанию — сборка проекта
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): $(OBJS)
	@if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -o $@ $^

# Правило для сборки объектных файлов
build/%.o: %.cpp
	@if not exist build mkdir build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для очистки (удаление объектных файлов и исполняемого файла)
clean:
	del /Q build\*.o build\main.exe

# Правило для повторной сборки всего проекта
rebuild: clean all
