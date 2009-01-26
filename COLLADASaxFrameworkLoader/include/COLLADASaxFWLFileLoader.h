/*
    Copyright (c) 2008 NetAllied Systems GmbH

    This file is part of COLLADASaxFrameworkLoader.

    Licensed under the MIT Open Source License, 
    for details please see LICENSE file or the website
    http://www.opensource.org/licenses/mit-license.php
*/

#ifndef __COLLADASAXFWL_FILELOADER_H__
#define __COLLADASAXFWL_FILELOADER_H__

#include "COLLADASaxFWLPrerequisites.h"
#include "COLLADAFWUniqueId.h"
#include "COLLADABUURI.h"

#include "COLLADASaxFWLIFilePartLoader.h"
#include "GeneratedSaxParserLibxmlSaxParser.h"
#include "COLLADASaxFWLColladaParserAutoGenPrivate.h"

namespace COLLADABU
{
	class URI;
}

namespace COLLADAFW
{
	class IWriter;
	class Object;
}


namespace COLLADASaxFWL
{
	class Loader;
	class FilePartLoader;

	/** Loader to a COLLADA document. Referenced documents are not loaded.*/
	class FileLoader : public IFilePartLoader, public ColladaParserAutoGenPrivate
    {
	private:
	
		/** The collada loader */
		Loader* mColladaLoader;

		/** The uri of the file that should be imported.*/
		COLLADABU::URI mFileURI;

		/** The parent (in the notion of the framework  data model) of the currently parsed element.*/
		COLLADAFW::Object* mObject;

		GeneratedSaxParser::LibxmlSaxParser mLibxmlSaxParse;


	public:

        /** Constructor.
		@param colladaLoader The collada loader this file loader is being used by. Used to retrieve document 
		global properties.
		@param fileURI The name of the file to be loaded.*/
		FileLoader ( Loader* colladaLoader, const COLLADABU::URI& fileURI );

        /** Destructor. */
        virtual ~FileLoader();

		/** Sets the parser to @a parserToBeSet.*/
		void setParser(IFilePartLoader* parserToBeSet);

		/** Loads the data into the frame work data model.*/
		bool load();

		/** Returns the absolute uri of the currently parsed file*/
		const COLLADABU::URI& getFileUri();



	protected:
		/** Returns a pointer to the collada loader. */
		Loader* getColladaLoader () { return mColladaLoader; }

		/** Returns a const pointer to the collada document. */
		const Loader* getColladaLoader () const { return mColladaLoader; }

		/** Starts loading a visual scene.*/
		virtual bool begin__geometry( const geometry__AttributeData& attributeData );

		/** Starts loading a visual scene.*/
		virtual bool begin__visual_scene( const visual_scene__AttributeData& attributeData );

		/** Starts loading a library nodes.*/
		virtual bool begin__library_nodes( const library_nodes__AttributeData& attributeData );



    private:

        /** Disable default copy ctor. */
		FileLoader( const FileLoader& pre );

        /** Disable default assignment operator. */
		const FileLoader& operator= ( const FileLoader& pre );


	};
	
} // namespace COLLADASaxFWL

#endif // __COLLADASAXFWL_FILELOADER_H__