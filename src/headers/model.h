#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>

#include "shader.h"
#include "mesh.h"

class Model
{
public:
    std::vector<Texture> loadedTextures;
    std::vector<Mesh> meshes;
    std::string directory;
    bool gammaCorrection;

public:
    Model(std::string const &path, bool isUV_flipped = true, bool gamma = false);
    void Draw(Shader *shader);

private:
    void loadModel(std::string const &path, bool isUV_flipped);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
};

unsigned int TextureFromFile(const char *path, const std::string &directory, bool gamma = false);

#endif