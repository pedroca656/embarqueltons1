#include <hellfire.h>

void task(void){
	int32_t jobs, id;

	id = hf_selfid();

	printf("\n%s (%d)[%d][%d]", hf_selfname(), id, hf_jobs(id), hf_dlm(id));

	for(;;){
		jobs = hf_jobs(id);
		printf("\n%s (%d)[%d][%d]", hf_selfname(), id, hf_jobs(id), hf_dlm(id));
		while (jobs == hf_jobs(id));
	}
}

void genAPTask(void){
	int32_t jobs, id;

	for(;;)
	{
		int32_t r = random() % (500 - 50) + 50;
		delay_ms(r);
		hf_spawn(task, 0, 3, 0, "Task AP", 2048);
	}
}

void app_main(void){

	// hf_spawn(genAPTask, 0, 0, 0, "genAPTask", 2048);

	hf_spawn(task, 4, 1, 4, "task RT a", 2048);
	hf_spawn(task, 8, 2, 8, "task RT b", 2048);
	hf_spawn(genAPTask, 0, 0, 0, "task RT c", 2048);

	//hf_spawn(genAPTask, 0, 0, 0, "GEN task AP 1", 2048);
	//hf_spawn(task, 0, 2, 0, "task AP 2", 2048);
	//hf_spawn(task, 0, 6, 0, "task AP 3", 2048);


}
