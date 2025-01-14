// Copyright 2023-2023 the openage authors. See copying.md for legal info.

#include "game_state.h"

#include <nyan/database.h>

#include "gamestate/game_entity.h"

namespace openage::gamestate {

GameState::GameState(const std::shared_ptr<nyan::Database> &db,
                     const std::shared_ptr<openage::event::EventLoop> &event_loop) :
	event::State{event_loop},
	db_view{db->new_view()} {
}

const std::shared_ptr<nyan::View> &GameState::get_nyan_db() {
	return this->db_view;
}

void GameState::add_game_entity(const std::shared_ptr<GameEntity> &entity) {
	if (this->game_entities.contains(entity->get_id())) [[unlikely]] {
		throw Error(MSG(err) << "Game entity with ID " << entity->get_id() << " already exists");
	}
	this->game_entities[entity->get_id()] = entity;
}

const std::shared_ptr<GameEntity> &GameState::get_game_entity(entity_id_t id) const {
	if (!this->game_entities.contains(id)) [[unlikely]] {
		throw Error(MSG(err) << "Game entity with ID " << id << " does not exist");
	}
	return this->game_entities.at(id);
}

const std::unordered_map<entity_id_t, std::shared_ptr<GameEntity>> &GameState::get_game_entities() const {
	return this->game_entities;
}

const std::shared_ptr<assets::ModManager> &GameState::get_mod_manager() const {
	return this->mod_manager;
}

void GameState::set_mod_manager(const std::shared_ptr<assets::ModManager> &mod_manager) {
	this->mod_manager = mod_manager;
}

} // namespace openage::gamestate
