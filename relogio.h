int t(void) //para tempo
{
time_t t;
time(&t);
printf("Data e tempo:%s\n",ctime(&t));

return 0 ;
}
