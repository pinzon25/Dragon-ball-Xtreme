#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"


#include<string.h>

// Constructor
ModuleFonts::ModuleFonts() : Module()
{}

// Destructor
ModuleFonts::~ModuleFonts()
{}

// Load new texture from file path
int ModuleFonts::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if(texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = App->textures->Load(texture_path);

	if(tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for(; id < MAX_FONTS; ++id)
		if(fonts[id].graphic == nullptr)
			break;

	if(id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	fonts[id].graphic = tex;
	fonts[id].rows = rows;
	fonts[id].len = strlen(characters); 

	// TODO 1: Finish storing font data
	uint w, h;
	App->textures->GetSize(tex, w, h);
	fonts[id].row_chars = 30;
	fonts[id].char_w = w/strlen(characters);
	fonts[id].char_h = h;
	strcpy_s(fonts[id].table, characters);
	
	
	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void ModuleFonts::UnLoad(int font_id)
{
	if(font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].graphic != nullptr)
	{
		App->textures->Unload(fonts[font_id].graphic);
		fonts[font_id].graphic = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

// Render text using a bitmap font
void ModuleFonts::BlitText(int x, int y, int font_id, const char* text) const
{
	if(text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);

	rect.w = font->char_w;
	rect.h = font->char_h;

	int inTable;
	for(uint i = 0; i < len; ++i)
	{
		for (int j = 0; j < strlen(font->table); j++)
		{
			if (text[i] == fonts->table[j]) {
				inTable = j;
				break;
			}
		}
		SDL_Rect charRec;
		charRec.x = inTable * font->char_w;
		charRec.y = 0;
		charRec.w = font->char_w;
		charRec.h = font->char_h;
		App->render->Blit(font->graphic, x, y, &charRec, 1.0f, false);
		x += font->char_w;
		
	}
}
