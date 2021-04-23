#include "RenderComponent.h"

Engine::Components::CRenderComponent::CRenderComponent(String name, CActor* owner, Vector location, Vector rotation, Vector scale)
	:CComponent(name,owner), Location(location), Rotation(rotation),Scale(scale)
{
}

Engine::Components::CRenderComponent::CRenderComponent(String name, CActor* owner)
	:CComponent(name, owner)
{
}

void Engine::Components::CRenderComponent::Update(float deltaTime)
{
	Draw();
}

void Engine::Components::CRenderComponent::Init()
{
}
