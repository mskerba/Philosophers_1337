# Philosophers_1337
- **Threads**
    - **What is a Thread?**
        
        > Un thread est un flux de séquence unique dans un [processus](https://www.geeksforgeeks.org/difference-between-program-and-process/). Étant donné que les threads possèdent certaines des propriétés des processus, ils sont parfois appelés *processus légers* .
        > 
    - **What are the differences between process and thread?**
        
        > Les threads ne sont pas indépendants les uns des autres, comme les processus, par conséquent, les threads partagent avec d'autres threads leur section de code, leur section de données et les ressources du système d'exploitation, telles que les fichiers ouverts et les signaux. Mais, comme un processus, un thread a son propre [compteur de programme (PC)](https://www.techtarget.com/whatis/definition/program-counter#:~:text=A%20program%20counter%20is%20a,its%20stored%20value%20by%201.), un ensemble de [registres](https://www.techtarget.com/whatis/definition/register) et stack.
        > 
    - **Why Multithreading?**
        
        > Les threads sont un moyen populaire d'améliorer l'application grâce au [parallélisme.](https://www.heavy.ai/technical-glossary/parallel-computing#:~:text=Parallel%20computing%20is%20a%20type,an%20overall%20larger%2C%20complex%20problem.) Par exemple, dans un navigateur, plusieurs onglets peuvent être des threads différents. MS Word utilise plusieurs threads, un thread pour formater le texte, un autre thread pour traiter les entrées, etc.
        > 
        
        Les threads fonctionnent plus rapidement que les processus pour les raisons suivantes :
        
        1) La création de threads est beaucoup plus rapide.
        
        2) La commutation de contexte entre les threads est beaucoup plus rapide.
        
        3) Les threads peuvent être terminés facilement
        
        4) La communication entre les threads est plus rapide.
        
    - **Can we write multithreading programs in C?**
        
        > Contrairement à Java, le multithreading n'est pas pris en charge par la norme de langage. **[Les threads POSIX (ou Pthreads)](http://en.wikipedia.org/wiki/POSIX_Threads)** sont une norme POSIX pour les threads. L'implémentation de pthread est disponible avec le compilateur gcc.
        > 
    - **Un programme C simple pour démontrer l'utilisation des fonctions de base de pthread**
        
        > ****Veuillez noter que le programme ci-dessous ne peut être compilé qu'avec des compilateurs C avec la bibliothèque pthread.
        > 
        > 
        > ```c
        > #include <stdio.h>
        > #include <stdlib.h>
        > #include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
        > #include <pthread.h>
        >   
        > // A normal C function that is executed as a thread 
        > // when its name is specified in pthread_create()
        > void *myThreadFun(void *vargp)
        > {
        >     sleep(1);
        >     printf("Printing GeeksQuiz from Thread \n");
        >     return NULL;
        > }
        >    
        > int main()
        > {
        >     pthread_t thread_id;
        >     printf("Before Thread\n");
        >     pthread_create(&thread_id, NULL, myThreadFun, NULL);
        >     pthread_join(thread_id, NULL);
        >     printf("After Thread\n");
        >     exit(0);
        > }
        > ```
        > 
        > Dans main(), nous déclarons une variable appelée thread_id, qui est de type pthread_t, qui est un entier utilisé pour identifier le thread dans le système. Après avoir déclaré thread_id, nous appelons la fonction pthread_create() pour créer un thread.pthread_create() prend 4 arguments.Le premier argument est un pointeur vers thread_id qui est défini par cette fonction.Le deuxième argument spécifie les attributs. Si la valeur est NULL, les attributs par défaut doivent être utilisés.Le troisième argument est le nom de la fonction à exécuter pour le thread à créer.Le quatrième argument est utilisé pour passer des arguments à la fonction, myThreadFun.La fonction pthread_join() pour les threads est l'équivalent de wait() pour les processus. Un appel à pthread_join bloque le thread appelant jusqu'à ce que le thread avec l'identifiant égal au premier argument se termine.
        > 
    - **Thread functions**
        
        > Dans un **système d'exploitation Unix/Linux** , les **langages C/C++** fournissent l' API standard **[POSIX thread(pthread)](https://www.geeksforgeeks.org/multithreading-c-2/)** (interface de programme d'application) pour toutes les fonctions liées aux threads. Cela nous permet de créer plusieurs threads pour un flux de processus simultané. Il est plus efficace sur les systèmes multiprocesseurs ou multicœurs où les threads peuvent être implémentés au niveau du noyau pour atteindre la vitesse d'exécution. Des gains peuvent également être trouvés dans les systèmes monoprocesseurs en exploitant la latence dans les E/S ou d'autres fonctions système qui peuvent arrêter un processus.
        > 
        > 
        > Nous devons inclure le fichier d'en-tête pthread.h au début du script pour utiliser toutes les fonctions de la bibliothèque pthreads. Pour exécuter le fichier c, nous devons utiliser le -pthread ou -lpthread dans la ligne de commande lors de la compilation du fichier.
        > 
        > ```
        > cc -pthread fichier.c ou
        > cc -lpthread fichier.c
        > ```
        > 
        > Les **fonctions** définies dans la **bibliothèque pthreads** incluent :
        > 
        > 1. ***pthread_create :***
        >     
        >     utilisé pour créer un nouveau thread
        >     
        >     **Syntaxe:**
        >     
        >     ```
        >     int pthread_create(pthread_t * fil,
        >                        const pthread_attr_t * attr,
        >                        void * (*start_routine)(void *),
        >                        vide *arg);
        >     ```
        >     
        >     **Paramètres:**
        >     
        >     - **thread :**
        >         
        >         pointeur vers une valeur entière non signée qui renvoie l'identifiant de thread du thread créé.
        >         
        >     - **attr :**
        >         
        >         pointeur vers une structure utilisée pour définir les attributs de thread tels que l'état détaché, la politique de planification, l'adresse de la pile, etc. Défini sur NULL pour les attributs de thread par défaut.
        >         
        >     - **start_routine :**
        >         
        >         pointeur vers un sous-programme exécuté par le thread. Le type de retour et le type de paramètre de la sous-routine doivent être de type void *. La fonction a un seul attribut mais si plusieurs valeurs doivent être transmises à la fonction, une structure doit être utilisée.
        >         
        >     - **arg :**
        >         
        >         pointeur vers void qui contient les arguments de la fonction définie dans l'argument précédent
        >         
        > 2. ***pthread_exit :***
        >     
        >     utilisé pour terminer un thread
        >     
        >     **Syntaxe:**
        >     
        >     ```
        >     void pthread_exit(void *retval);
        >     
        >     ```
        >     
        >     **Paramètres :** cette méthode accepte un paramètre obligatoire **retval** qui est le pointeur vers un entier qui stocke l'état de retour du thread terminé. La portée de cette variable doit être globale afin que tout thread attendant de rejoindre ce thread puisse lire l'état de retour.
        >     
        > 3. ***pthread_join :***
        >     
        >     utilisé pour attendre la fin d'un thread.
        >     
        >     **Syntaxe:**
        >     
        >     ```
        >     int pthread_join(pthread_t ème,
        >                      void **thread_return);
        >     ```
        >     
        >     **Paramètre :** cette méthode accepte les paramètres suivants :
        >     
        >     - **th :**
        >         
        >         identifiant de thread du thread qu'attend le thread courant.
        >         
        >     - **thread_return :**
        >         
        >         pointeur vers l'emplacement où le statut de sortie du thread mentionné dans th est stocké.
        >         
        > 4. ***pthread_self :***
        >     
        >     utilisé pour obtenir l'identifiant du thread actuel.
        >     
        >     **Syntaxe:**
        >     
        >     ```
        >     pthread_t pthread_self(vide);
        >     
        >     ```
        >     
        > 5. ***pthread_equal :***
        >     
        >     compare si deux threads sont identiques ou non. Si les deux threads sont égaux, la fonction renvoie une valeur non nulle sinon zéro.
        >     
        >     **Syntaxe:**
        >     
        >     ```
        >     int pthread_equal(pthread_t t1,
        >                       pthread_t t2);
        >     ```
        >     
        >     **Paramètres :** cette méthode accepte les paramètres suivants :
        >     
        >     - t1 : l'identifiant du premier thread
        >     - t2 : l'identifiant de thread du deuxième thread
        > 6. ***pthread_cancel :***
        >     
        >     utilisé pour envoyer une demande d'annulation à un thread
        >     
        >     **Syntaxe:**
        >     
        >     ```
        >     int pthread_cancel(pthread_t thread);
        >     
        >     ```
        >     
        >     **Paramètre :** Cette méthode accepte un **thread** de paramètre obligatoire qui est l'ID de thread du thread auquel la demande d'annulation est envoyée.
        >     
        > 7. ***pthread_detach :***
        >     
        >     utilisé pour détacher un thread. Un thread détaché ne nécessite pas qu'un thread se joigne à la fin. Les ressources du thread sont automatiquement libérées après l'arrêt si le thread est détaché.
        >     
        >     **Syntaxe:**
        >     
        >     ```
        >     int pthread_detach(pthread_t thread);
        >     
        >     ```
        >     
        >     **Paramètre :** cette méthode accepte un paramètre obligatoire **thread** qui est l'identifiant de thread du thread qui doit être détaché.
        >     
        > 
        > **Exemple :** Une implémentation simple des threads peut être la suivante :
        > 
        > ```c
        > 
        > #include <pthread.h>
        > #include <stdio.h>
        > #include <stdlib.h>
        >   
        > void* func(void* arg)
        > {
        >     pthread_detach(pthread_self());
        >     printf("Inside the thread\n");
        >     pthread_exit(NULL);
        > }
        >   
        > void fun()
        > {
        >     pthread_t ptid;
        >     pthread_create(&ptid, NULL, &func, NULL);
        >     printf("This line may be printed"
        >            " before thread terminates\n");
        > if(pthread_equal(ptid, pthread_self())
        >         printf("Threads are equal\n");
        >     else
        >         printf("Threads are not equal\n");
        >       pthread_join(ptid, NULL);
        >   
        >     printf("This line will be printed"
        >            " after thread ends\n");
        >     pthread_exit(NULL);
        > }
        > int main()
        > {
        >     fun();
        >     return 0;
        > }
        > ```
        > 
        > **Output:**
        > 
        > ```
        > This line may be printed before thread terminates
        > Threads are not equal
        > Inside the thread
        > This line will be printed after thread ends
        > ```
        > 
        > **Explication :** Ici, deux threads d'exécution sont créés dans le code. L'ordre des lignes de sortie des deux threads peut être inter changé en fonction du thread traité précédemment. Le thread principal attend le thread nouvellement créé pour quitter. Par conséquent, la dernière ligne de la sortie n'est imprimée qu'après la sortie du nouveau thread. Les threads peuvent se terminer indépendamment les uns des autres en n'utilisant pas la fonction *pthread_join* . Si nous voulons terminer le nouveau thread manuellement, nous pouvons utiliser *pthread_cancel* pour le faire.
        > 
        > **Remarque :** Si nous utilisons exit() au lieu de **pthread_exit()** pour terminer un thread, l'ensemble du processus avec tous les threads associés sera terminé même si certains des threads sont encore en cours d'exécution.
        > 
- **Threads**`(The Linux Programming Interface)`
    
    [](https://sciencesoftcode.files.wordpress.com/2018/12/the-linux-programming-interface-michael-kerrisk-1.pdf)
    
    - **INTRODUCTION**
        
        Comme les processus, les threads sont un mécanisme qui permet à une application d'effectuer plusieurs tâches simultanément. Un même processus peut contenir plusieurs threads. Tous ces threads exécutent indépendamment le même programme et partagent tous la même mémoire globale, y compris les données initialisées, les données non initialisées et les segments de tas. (Un processus UNIX traditionnel est simplement un cas particulier de processus multithread ; c'est un processus qui ne contient qu'un seul thread.)
        
        > En particulier, l'emplacement des stacks par thread peut être entremêlé avec des bibliothèques partagées et des régions de mémoire partagée, selon l'ordre dans lequel les threads sont créés, les bibliothèques partagées chargées et les régions de mémoire partagée attachées. De plus, l'emplacement des stacks par thread peut varier en fonction de la distribution Linux.
        > 
        
        Les threads d'un processus peuvent s'exécuter simultanément. Sur un système multiprocesseur, plusieurs threads peuvent s'exécuter en parallèle. Si un thread est bloqué sur les I/O, les autres les threads sont toujours éligibles à l'exécution. (Bien qu'il soit parfois utile de créer un thread séparé uniquement dans le but d'effectuer des I/O, il est souvent préférable de utiliser l'un des modèles d'I/O alternatifs .)
        
        - **Quatre threads s'exécutant dans un processu**s
            
            ![Screen Shot 2022-06-19 at 10.51.46 AM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/bb28bb9e-2f6b-4ed9-abe9-08f85ad14a55/Screen_Shot_2022-06-19_at_10.51.46_AM.png)
            
            Les threads offrent des avantages par rapport aux processus dans certaines applications. Considérez l'approche UNIX traditionnelle pour atteindre la simultanéité en créant plusieurs processus. Un exemple de ceci est une conception de serveur de réseau dans laquelle un processus parent accepte les connexions entrantes des clients, puis utilise fork() pour créer un processus enfant séparé pour gérer la communication avec chaque client. Une telle conception permet de servir plusieurs clients simultanément. Bien que cette approche fonctionne bien pour de nombreux scénarios, elle présente les limitations suivantes dans certaines applications :
            
            - Il est difficile de partager des informations entre les processus. Étant donné que le parent et l'enfant ne partagent pas de mémoire (autre que le segment de texte en lecture seule), nous devons utiliser une forme de communication inter processus afin d'échanger des informations entre les processus.
            - La création de processus avec fork() est relativement coûteuse. Même avec la technique de copie sur écriture décrite dans la section 24.2.2, la nécessité de dupliquer divers attributs de processus tels que les tables de pages et les tables de descripteurs de fichiers signifie qu'un appel fork() prend encore du temps
            
            Les discussions traitent de ces deux problèmes :
            
            - Le partage d'informations entre les threads est simple et rapide. Il s'agit simplement de copier des données dans des variables partagées (globales ou de tas). Cependant, afin d'éviter les problèmes qui peuvent survenir lorsque plusieurs threads tentent de mettre à jour les mêmes informations, nous devons utiliser les techniques de synchronisation décrites au chapitre 30.
            - La création de threads est plus rapide que la création de processus, généralement dix fois plus rapide ou mieux. (Sous Linux, les threads sont implémentés à l'aide de l'appel système clone() et le Tableau 28-3, à la page 610, montre les différences de vitesse entre fork() et clone().) La création de threads est plus rapide car de nombreux attributs qui doivent être dupliqués dans un enfant créé par fork() sont plutôt partagés entre les threads. En particulier, la duplication par copie sur écriture des pages de mémoire n'est pas nécessaire, pas plus que la duplication des tables de pages.
                
                ![Screen Shot 2022-06-19 at 12.12.19 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f62efdfd-01b0-4aa6-b223-ce1f0d0a21cb/Screen_Shot_2022-06-19_at_12.12.19_PM.png)
                
            
            Outre la mémoire globale, les threads partagent également un certain nombre d'autres attributs (c'est-à-dire que ces attributs sont globaux pour un processus, plutôt que spécifiques à un thread). Ces attributs incluent les éléments suivants :
            
            - process ID and parent process ID;
            - process group ID and session ID;
            - controlling terminal;
            - process credentials (user and group IDs);
            - open file descriptors;
            - record locks created using fcntl();
            - signal dispositions;
            - file system–related information: umask, current working directory, and root
            directory;
            - CPU time consumed (as returned by times());CPU time consumed (as returned by times());
            
        
        ![Screen Shot 2022-06-19 at 12.12.44 PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/951da754-82df-428d-9bca-ab71f74fa0f4/Screen_Shot_2022-06-19_at_12.12.44_PM.png)
        
        - **Return value from Pthreads functions**
            
            La méthode traditionnelle de retour d'état à partir d'appels système et de certaines fonctions de bibliothèque consiste à renvoyer 0 en cas de succès et –1 en cas d'erreur, errno étant défini pour indiquer l'erreur. Les fonctions de l'API Pthreads font les choses différemment. Toutes les fonctions Pthreads renvoient 0 en cas de succès ou une valeur positive en cas d'échec. La valeur d'échec est l'une des mêmes valeurs qui peuvent être placées dans errno par les appels système UNIX traditionnels. Étant donné que chaque référence à errno dans un programme threadé porte la surcharge d'un appel de fonction, nos exemples de programmes n'assignent pas directement la valeur de retour d'une fonction Pthreads à errno. Au lieu de cela, nous utilisons une variable intermédiaire et employons notre fonction de diagnostic errExitEN() (Section 3.5.2), comme ceci :
            
            ```c
            pthread_t *thread;
            int s;
            s = pthread_create(&thread, NULL, func, &arg);
            if (s != 0)
             errExitEN(s, "pthread_create")
            ```
            
        - **Thread Creation**
            
            Lorsqu'un programme est démarré, le processus résultant consiste en un seul thread, appelé thread initial ou principal. Dans cette section, nous verrons comment créer des threads supplémentaires.
            
            <aside>
            💡 The pthread_create() function creates a new thread
            
            </aside>
            
            ```c
            #include <pthread.h>
            int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
             void *(*start)(void *), void *arg);
            ```
            
            <aside>
            💡 Returns 0 on success, or a positive error number on error
            
            </aside>
            
        - **Thread Termination**
            
            L'exécution d'un thread se termine de l'une des manières suivantes :
            
            - La fonction start du thread effectue un retour en spécifiant une valeur de retour pour le thread.
            - The thread calls pthread_exit().
            - The thread is canceled using pthread_cancel().
            - Any of the threads calls exit(), or the main thread performs a return (in the
            main() function), which causes all threads in the process to terminate immediately.
            
            <aside>
            💡 The pthread_exit() function terminates the calling thread, and specifies a return
            value that can be obtained in another thread by calling pthread_join().
            
            </aside>
            
            ```c
            include <pthread.h>
            void pthread_exit(void *retval);
            ```
            
        - **Joining with a Terminated Thread**
            
            The pthread_join() function waits for the thread identified by thread to terminate. (If
            that thread has already terminated, pthread_join() returns immediately.) This operation is termed joining.
            
            ```c
            include <pthread.h>
            int pthread_join(pthread_t thread, void **retval);
            ```
            
            <aside>
            💡 Returns 0 on success, or a positive error number on error
            
            </aside>
            
            Si retval est un pointeur non NULL, alors il reçoit une copie de la valeur de retour du thread terminé, c'est-à-dire la valeur qui a été spécifiée lorsque le thread a effectué un retour ou appelé pthread_exit(). L'appel de pthread_join() pour un ID de thread qui a déjà été joint peut conduire à un comportement imprévisible ; par exemple, il peut à la place se joindre à un thread créé ultérieurement qui a réutilisé le même ID de thread.
            
            Si un thread n'est pas détaché (voir Section 29.7), alors nous devons le joindre en utilisant pthread_join(). Si nous échouons à le faire, alors, lorsque le thread se termine, il produit le thread équivalent d'un processus zombie (Section 26.2). En plus de gaspiller des ressources système, si suffisamment de threads zombies s'accumulent, nous ne pourrons pas créer de threads supplémentaires.
            
        - **Detaching a Thread**
            
            Par défaut, un thread est joignable, ce qui signifie que lorsqu'il se termine, un autre thread peut obtenir son état de retour en utilisant pthread_join(). Parfois, nous ne nous soucions pas du statut de retour du thread ; nous voulons simplement que le système nettoie et supprime automatiquement le thread lorsqu'il se termine. Dans ce cas, nous pouvons marquer le thread comme détaché, en appelant pthread_detach() en spécifiant l'identifiant du thread dans thread.
            
            ```c
            #include <pthread.h>
            int pthread_detach(pthread_t thread);
            ```
            
            <aside>
            💡 Returns 0 on success, or a positive error number on error
            
            </aside>
            
            As an example of the use of pthread_detach(), a thread can detach itself using the following call:
                                 pthread_detach(pthread_self());
            
            Une fois qu'un thread a été détaché, il n'est plus possible d'utiliser pthread_join() pour obtenir son statut de retour, et le thread ne peut plus être rendu joignable. Détacher un thread ne l'immunise pas contre un appel à exit() dans un autre thread ou un retour dans le thread principal. Dans un tel événement, tous les threads du processus sont immédiatement arrêtés, qu'ils soient joignables ou détachés. En d'autres termes, pthread_detach() contrôle simplement ce qui se passe après la fin d'un thread, pas comment ni quand il se termine.
            
- **Mutexes**`(The Linux Programming Interface)`
    
    [](https://sciencesoftcode.files.wordpress.com/2018/12/the-linux-programming-interface-michael-kerrisk-1.pdf)
    
    - **Definition**
        
        Dans ce chapitre, nous décrivons deux outils que les threads peuvent utiliser pour synchroniser leurs actions : les mutex et les variables de condition. Les mutex permettent aux threads de synchroniser leur utilisation d'une ressource partagée, de sorte que, par exemple, un thread n'essaie pas d'accéder à une variable partagée en même temps qu'un autre thread la modifie. Les variables de condition effectuent une tâche complémentaire : elles permettent aux threads de s'informer mutuellement qu'une variable partagée (ou une autre ressource partagée) a changé d'état.
        
    - **Protecting Accesses to Shared Variables**
        
        L'un des principaux avantages des threads est qu'ils peuvent partager des informations via des variables globales. Cependant, ce partage facile a un coût : il faut veiller à ce que plusieurs threads n'essayent pas de modifier la même variable en même temps, ou qu'un thread n'essaie pas de lire la valeur d'une variable pendant qu'un autre thread est en train de modifier le. Le terme section critique est utilisé pour désigner une section de code qui accède à une ressource partagée et dont l'exécution doit être atomique ; c'est-à-dire que son exécution ne doit pas être interrompue par un autre thread qui accède simultanément à la même ressource partagée. Le Listing 30-1 fournit un exemple simple du type de problèmes qui peuvent survenir lorsque les ressources partagées ne sont pas accessibles de manière atomique. Ce programme crée deux threads, chacun exécutant la même fonction. La fonction exécute une boucle qui increment de manière répétée une variable globale, glob, en copiant glob dans la variable locale loc, en incrémentant loc et en copiant loc dans glob. (Puisque loc est une variable automatique allouée sur la pile par thread, chaque thread a sa propre copie de cette variable.) Le nombre d'itérations de la boucle est déterminé par l'argument de ligne de commande fourni au programme, ou par une valeur par défaut valeur, si aucun argument n'est fourni.
        
        ```c
        #include <pthread.h>
        #include "tlpi_hdr.h"
        
        static int glob = 0;
        
        static void  threadFunc(void *arg)
        {
        	int loops = *((int *) arg);
        	int loc, j;
        	for (j = 0; j < loops; j++)
        	{
        			 loc = glob;
        			 loc++;
        			 glob = loc;
        	}
        	return NULL;
        }
        
        int main(int argc, char *argv[])
        {
        	pthread_t t1, t2;
        	int loops, s;
        
        	loops = (argc > 1) ? getInt(argv[1], GN_GT_0, "num-loops") : 10000000;
        	s = pthread_create(&t1, NULL, threadFunc, &loops);
        	if (s != 0)
        	errExitEN(s, "pthread_create");
        	s = pthread_create(&t2, NULL, threadFunc, &loops);
        	if (s != 0)
        			errExitEN(s, "pthread_create");
        	s = pthread_join(t1, NULL);
        	if (s != 0)
        		errExitEN(s, "pthread_join");
        	s = pthread_join(t2, NULL);
        	if (s != 0)
        		errExitEN(s, "pthread_join");
        	printf("glob = %d\n", glob);
        	exit(EXIT_SUCCESS);
        }\
        ```
        
- **Semaphores**
    - **Definition**
        
        Ce chapitre décrit les sémaphores POSIX, qui permettent aux processus et aux threads de synchroniser l'accès aux ressources partagées. Dans le chapitre 47, nous avons décrit les sémaphores du système V, et nous supposerons que le lecteur est familiarisé avec les concepts généraux de sémaphore et la justification de l'utilisation des sémaphores qui ont été présentés au début de ce chapitre. Au cours de ce chapitre, nous ferons des comparaisons entre les sémaphores POSIX et les sémaphores System V pour clarifier en quoi ces deux API de sémaphores sont identiques et en quoi elles diffèrent.
