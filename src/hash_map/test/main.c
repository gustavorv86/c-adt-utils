
#include <stdio.h>
#include <stdlib.h>
#include <hash_map.h>

int main() {
	HASH_MAP_T map;

	const char * key = NULL;
	const char * value = NULL;

	hash_map_new(&map);

	hash_map_put(&map, "perro", "dog");
	hash_map_put(&map, "gato", "cat");
	hash_map_put(&map, "mariposa", "butterfly");
	hash_map_put(&map, "caballo", "horse");
	hash_map_put(&map, "toro", "bull");
	hash_map_put(&map, "lobo", "wolf");
	hash_map_put(&map, "leon", "lion");
	hash_map_put(&map, "serpiente", "smake");
	hash_map_put(&map, "pajaro", "bird");
	hash_map_put(&map, "oso", "bear");
	hash_map_put(&map, "jirafa", "giraffe");

	hash_map_print(map);
	printf("\n");

	printf("TEST: hash_map_get \n");
	key = "perro";
	printf("[%s]: %s \n", key, hash_map_get(map, key));
	key = "dog";
	printf("[%s]: %s \n", key, hash_map_get(map, key));
	printf("END TEST: hash_map_get \n\n");

	printf("TEST: hash_map_remove \n");
	key = "gato";
	printf("Removing key %s \n", key);
	hash_map_remove(&map, key);
	hash_map_print(map);
	printf("END TEST: hash_map_remove \n\n");

	printf("TEST: hash_map_put_replace_value \n");
	key = "toro";
	value = "torus";
	printf("Replacing key %s, value %s \n", key, value);
	hash_map_put(&map, "toro", "torus");
	hash_map_print(map);
	printf("END TEST: hash_map_put_replace_value \n\n");

	printf("TEST: hash_map_get_keys \n");
	KEYSET_T map_keys = hash_map_keyset(map);
	for(unsigned int i = 0; i < map_keys.size; i++) {
		printf("%s ", map_keys.keys[i]);
	}
	printf("\n");
	hash_map_keyset_destroy(&map_keys);
	printf("END TEST: hash_map_get_keys \n\n");

	printf("TEST: hash_map_clear \n");
	hash_map_clear(&map);
	printf("END TEST: hash_map_clear \n\n");

	printf("TEST: hash_map_put after clear \n");
	hash_map_put(&map, "toro", "torus");
	hash_map_print(map);
	printf("END TEST: hash_map_put after clear \n\n");

	hash_map_destroy(&map);

	return (EXIT_SUCCESS);
}
