/*
	Copyright (C) 2014 - 2023
	by Iris Morelle <shadowm2006@gmail.com>
	Part of the Battle for Wesnoth Project https://www.wesnoth.org/

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY.

	See the COPYING file for more details.
*/

#pragma once

#include "gui/dialogs/modal_dialog.hpp"

namespace gui2
{
class label;
class button;
namespace dialogs
{

/**
 * @ingroup GUIWindowDefinitionWML
 *
 * A Preferences subdialog including a report on the location and size of the game's WML cache,
 * buttons to copy its path to clipboard or browse to it, and the possibility of clearing stale files from the cache or purging it entirely.
 * Key               |Type          |Mandatory|Description
 * ------------------|--------------|---------|-----------
 * path              | text_box     |yes      |Cache dir path.
 * copy              | @ref button  |yes      |Copies the cache path to clipboard.
 * browse            | @ref button  |yes      |Browses to the cache path using the platform's file management application.
 * size              | @ref label   |yes      |Current total size of the cache dir's contents.
 * clean             | @ref button  |yes      |Cleans the cache, erasing stale files not used by the Wesnoth version presently running the dialog.
 * purge             | @ref button  |yes      |Purges the cache in its entirety.
 */
class game_cache_options : public modal_dialog
{
public:
	/** Constructor. */
	game_cache_options();

	/**
	 * The display function.
	 *
	 * See @ref modal_dialog for more information.
	 */
	DEFINE_SIMPLE_DISPLAY_WRAPPER(game_cache_options)

private:
	std::string cache_path_;

	button* clean_button_;
	button* purge_button_;
	label* size_label_;

	void clean_cache_callback();
	bool clean_cache();

	void purge_cache_callback();
	bool purge_cache();

	void copy_to_clipboard_callback();

	void browse_cache_callback();

	void update_cache_size_display();

	virtual const std::string& window_id() const override;

	virtual void pre_show(window& window) override;

	virtual void post_show(window& window) override;
};

} // namespace dialogs
} // namespace gui2
