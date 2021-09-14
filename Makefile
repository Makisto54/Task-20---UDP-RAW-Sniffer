CC := gcc

TASK_1 := sniffer
TASK_2 := UDP/

.PHONY: all $(TASK_1) $(TASK_2) clean

all: $(TASK_1) $(TASK_2)

$(TASK_1): $(TASK_1).c
	$(CC) $(TASK_1).c -o $(TASK_1)

$(TASK_2):
	cd $(TASK_2) && make

clean:
	rm -rf $(TASK_1)
	cd $(TASK_2) && make clean
