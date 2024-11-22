# 定义编译器
CC = gcc

# 定义编译选项
CFLAGS = -Wall

# 定义目标文件名
TARGET = main

# 定义输出目录
OUT_DIR = out

# 自动获取所有的 .c 文件，生成对象文件列表，存放在 out 文件夹中
SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, $(OUT_DIR)/%.o, $(SRCS))

# 默认目标
all: $(TARGET)

# 创建 out 文件夹，并链接所有的对象文件生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译每个 .c 文件为 out 文件夹下的 .o 文件
$(OUT_DIR)/%.o: %.c | $(OUT_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 创建 out 目录
$(OUT_DIR):
	mkdir -p $(OUT_DIR)

# 清除编译生成的文件
clean:
	rm -rf $(OUT_DIR) $(TARGET)