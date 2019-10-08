
#include <stdio.h>
#include <stdlib.h>
#include <linked_map.h>

int main() {
	LINKED_MAP_T lmap;

	const char * key = NULL;
	const char * value = NULL;

	linked_map_new(&lmap);

	linked_map_put(&lmap, "perro", "dog");
	linked_map_put(&lmap, "gato", "cat");
	linked_map_put(&lmap, "mariposa", "butterfly");
	linked_map_put(&lmap, "caballo", "horse");
	linked_map_put(&lmap, "toro", "bull");
	linked_map_put(&lmap, "lobo", "wolf");
	linked_map_put(&lmap, "leon", "lion");
	linked_map_put(&lmap, "serpiente", "snake");
	linked_map_put(&lmap, "pajaro", "bird");
	linked_map_put(&lmap, "oso", "bear");
	linked_map_put(&lmap, "jirafa", "giraffe");

	linked_map_print(lmap);
	printf("\n");

	printf("TEST: linked_map_get \n");
	key = "perro";
	printf("[%s]: %s \n", key, linked_map_get(lmap, key));
	key = "dog";
	printf("[%s]: %s \n", key, linked_map_get(lmap, key));
	printf("END TEST: linked_map_get \n\n");

	printf("TEST: linked_map_remove \n");
	key = "gato";
	printf("Removing key %s \n", key);
	linked_map_remove(&lmap, key);
	linked_map_print(lmap);
	printf("END TEST: linked_map_remove \n\n");

	printf("TEST: linked_map_put_replace_value \n");
	key = "toro";
	value = "torus";
	printf("Replacing key %s, value %s \n", key, value);
	linked_map_put(&lmap, "toro", "torus");
	linked_map_print(lmap);
	printf("END TEST: linked_map_put_replace_value \n\n");

	printf("TEST: linked_map_get_keys \n");
	KEYSET_T lmap_keys = linked_map_keyset(lmap);
	for(unsigned int i = 0; i < lmap_keys.size; i++) {
		printf("%s ", lmap_keys.keys[i]);
	}
	printf("\n");
	linked_map_keyset_destroy(&lmap_keys);
	printf("END TEST: linked_map_get_keys \n\n");

	printf("TEST: linked_map_clear \n");
	linked_map_clear(&lmap);
	printf("END TEST: linked_map_clear \n\n");

	printf("TEST: linked_map_put after clear \n");
	linked_map_put(&lmap, "toro", "torus");
	linked_map_print(lmap);
	printf("END TEST: linked_map_put after clear \n\n");

	linked_map_destroy(&lmap);

	return (EXIT_SUCCESS);
}
