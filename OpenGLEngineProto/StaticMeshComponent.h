#pragma once
#include "Shader.h"
#include "RenderComponent.h"
#include "LoadedMeshData.h"
#include "Material.h"

struct Shader;
namespace Engine::Components
{
    class CStaticMeshComponent : public CRenderComponent
    {
        GENERATED_CLASS_BODY(StaticMeshComponent, RenderComponent,RenderComponents, Engine::Components)
    protected:
#pragma region ShaderData
        /*These are constant and set when shader is loaded, used to simplfy setting this kind of data*/

        uint shader_ambientLightIntensityId;
        uint shader_ambientLightReflectivityId;
        uint shader_ambientLightColorId;

        /*Buffer for mesh's verticies*/
        uint vertexBuffer;

        /*Buffer for mesh's uv data*/
        uint uvBuffer;

        uint shaderProgramId;
#pragma endregion

        LoadedMeshData mesh;

        Shader shader;
    public:
        Shader GetShader()const;

        CStaticMeshComponent(String shaderName,String name, CActor* owner, Vector Location, Vector Rotation, Vector Scale);

        CStaticMeshComponent(String shaderName, String name, CActor* owner);

        // Inherited via CRenderComponent
        virtual void EndDraw() override;
        virtual void BeingDraw()override;
    };
}

