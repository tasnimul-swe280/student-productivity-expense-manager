#include <stdio.h>
#include <string.h>

#define MAX 100

struct Task {
	char name[50];
	int deadline;
	int status; 
};

struct Expense {
	char category[20];
	float amount;
};

struct Task tasks[MAX];
struct Expense expenses[MAX];

int taskCount = 0;
int expenseCount = 0;

void addTask() {
	printf("Enter task name: ");
	scanf(" %[^\n]", tasks[taskCount].name);

	printf("Enter deadline (days): ");
	scanf("%d", &tasks[taskCount].deadline);

	tasks[taskCount].status = 0;
	taskCount++;
}

void viewTasks() {
	for (int i = 0; i < taskCount; i++) {
		printf("%d. %s | Deadline: %d | %s\n",
		       i + 1,
		       tasks[i].name,
		       tasks[i].deadline,
		       tasks[i].status ? "Done" : "Pending");
	}
}

void completeTask() {
	int n;
	printf("Enter task number to complete: ");
	scanf("%d", &n);

	if (n > 0 && n <= taskCount) {
		tasks[n - 1].status = 1;
	} else {
		printf("Invalid task number!\n");
	}
}

void addExpense() {
	printf("Enter category: ");
	scanf("%s", expenses[expenseCount].category);

	printf("Enter amount: ");
	scanf("%f", &expenses[expenseCount].amount);

	expenseCount++;
}

void viewExpenses() {
	float total = 0;

	for (int i = 0; i < expenseCount; i++) {
		printf("%s: %.2f\n",
		       expenses[i].category,
		       expenses[i].amount);
		total += expenses[i].amount;
	}

	printf("Total Expense: %.2f\n", total);
}

void smartSuggestion() {
	float total = 0;
	int pending = 0;

	for (int i = 0; i < expenseCount; i++)
		total += expenses[i].amount;

	for (int i = 0; i < taskCount; i++)
		if (tasks[i].status == 0)
			pending++;

	if (total > 5000)
		printf("Warning: You are spending too much!\n");

	if (pending > 1)
		printf("Alert: Too many pending tasks!\n");
}

int main() {
	int choice;

	while (1) {
		printf("\n1. Add Task\n2. View Tasks\n3. Complete Task\n");
		printf("4. Add Expense\n5. View Expense\n6. Smart Suggestion\n0. Exit\n");

		printf("Enter choice: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			addTask();
			break;
		case 2:
			viewTasks();
			break;
		case 3:
			completeTask();
			break;
		case 4:
			addExpense();
			break;
		case 5:
			viewExpenses();
			break;
		case 6:
			smartSuggestion();
			break;
		case 0:
			return 0;
		default:
			printf("Invalid choice\n");
		}
	}
}
