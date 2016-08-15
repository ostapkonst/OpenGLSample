#include "ap_model_loader.h"
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/mesh.h>
#include <stdlib.h>

void Load_Model(
	char * file_name, 
	unsigned int ** indices,
	float ** vertices,
	float ** uvs,
	float ** normals, 
	int * mod_size,
	int * ind_size
){
	const struct aiScene * scene = aiImportFile(file_name, 0);
	const struct aiMesh * mesh = scene->mMeshes[0];
	unsigned int i;

	*mod_size = mesh->mNumVertices;
	*ind_size = mesh->mNumFaces;

	*vertices = malloc(sizeof(float) * 3 * mesh->mNumVertices);
	for (i = 0; i < mesh->mNumVertices; i++) {
		(*vertices)[i * 3] = mesh->mVertices[i].x; 
		(*vertices)[i * 3 + 1] = mesh->mVertices[i].y; 
		(*vertices)[i * 3 + 2] = mesh->mVertices[i].z; 
	}

	*uvs = malloc(sizeof(float) * 2 * mesh->mNumVertices);
	for (i = 0; i < mesh->mNumVertices; i++){
		(*uvs)[i * 2] = mesh->mTextureCoords[0][i].x; 
		(*uvs)[i * 2 + 1] = mesh->mTextureCoords[0][i].y; 
	}

	*normals = malloc(sizeof(float) * 3 * mesh->mNumVertices);
	for (i = 0; i < mesh->mNumVertices; i++){
		(*normals)[i * 3] = mesh->mNormals[i].x; 
		(*normals)[i * 3 + 1] = mesh->mNormals[i].y; 
		(*normals)[i * 3 + 2] = mesh->mNormals[i].z; 
	}

	*indices = malloc(sizeof(unsigned int) * 3 * mesh->mNumFaces);
	for (i = 0; i < mesh->mNumFaces; i++){
		(*indices)[i * 3] = mesh->mFaces[i].mIndices[0]; 
		(*indices)[i * 3 + 1] = mesh->mFaces[i].mIndices[1]; 
		(*indices)[i * 3 + 2] = mesh->mFaces[i].mIndices[2]; 
	}
}
