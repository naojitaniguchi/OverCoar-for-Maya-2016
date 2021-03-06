#include "HairContextCommand.h"
#include "HairToolContext.h"
#include <maya/MSyntax.h>
#include <maya/MArgParser.h>
#include <maya/MDoubleArray.h>
#include <maya/MPxCommand.h>

 MPxContext* HairContextCommand::makeObj()
 {
	hairContext = new HairToolContext();
	return hairContext;
 }

 void* HairContextCommand::creator()
 {
 	return new HairContextCommand;
 }

 MStatus HairContextCommand::doEditFlags(){
	 MStatus status = MS::kSuccess;

	 MArgParser argData = parser();

	if (argData.isFlagSet(kColorFlag)) {
		double inputR, inputG, inputB;
		status = argData.getFlagArgument(kColorFlag, 0, inputR);
		status = argData.getFlagArgument(kColorFlag, 1, inputG);
		status = argData.getFlagArgument(kColorFlag, 2, inputB);
		if (!status) {
			status.perror("color flag parsing failed");
			return status;
		} 

		hairContext->setRedColor(inputR);
		hairContext->setGreenColor(inputG);
		hairContext->setBlueColor(inputB);
	}

	if (argData.isFlagSet(kThickFlag)) {
		double input;
		status = argData.getFlagArgument(kThickFlag, 0, input);
		if (!status) {
			status.perror("thick flag parsing failed");
			return status;
		} 

		hairContext->setThick(input);
	}

	if (argData.isFlagSet(kBrushFlag)) {
		int input;
		status = argData.getFlagArgument(kBrushFlag, 0, input);
		if (!status) {
			status.perror("brush flag parsing failed");
			return status;
		} 

		hairContext->setBrush(input);
	}

	if (argData.isFlagSet(kTransparencyFlag)) {
		double input;
		status = argData.getFlagArgument(kTransparencyFlag, 0, input);
		if (!status) {
			status.perror("transparency flag parsing failed");
			return status;
		} 

		hairContext->setTransparency(input);
	}

	if (argData.isFlagSet(kSpacingFlag)) {
		double input;
		status = argData.getFlagArgument(kSpacingFlag, 0, input);
		if (!status) {
			status.perror("spacing flag parsing failed");
			return status;
		} 

		hairContext->setSpacing(input);
	}

	 return status;
 }

  MStatus HairContextCommand::doQueryFlags(){
	 MStatus status = MS::kSuccess;

	 MArgParser argData = parser();

	if (argData.isFlagSet(kColorFlag)) {
		MDoubleArray results = MDoubleArray();
		results.append((double) hairContext->getRedColor());
		results.append((double) hairContext->getGreenColor());
		results.append((double) hairContext->getBlueColor());

		MPxCommand::setResult(results);
	}

	if (argData.isFlagSet(kThickFlag)) {
		setResult((double) hairContext->getThick());
	}

	if (argData.isFlagSet(kBrushFlag)) {
		setResult((int) hairContext->getBrush());
	}

	if (argData.isFlagSet(kTransparencyFlag)) {
		setResult((double) hairContext->getTransparency());
	}

	if (argData.isFlagSet(kSpacingFlag)) {
		setResult((double) hairContext->getSpacing());
	}

	 return status;
 }

  MStatus HairContextCommand::appendSyntax(){
	  MSyntax mySyntax = syntax();
        
        if (MS::kSuccess != mySyntax.addFlag(kColorFlag, kColorFlagLong, MSyntax::kDouble, MSyntax::kDouble, MSyntax::kDouble)) {
                return MS::kFailure;
        }
		if (MS::kSuccess != mySyntax.addFlag(kThickFlag, kThickFlagLong, MSyntax::kDouble)) {
                return MS::kFailure;
        }
		if (MS::kSuccess != mySyntax.addFlag(kBrushFlag, kBrushFlagLong, MSyntax::kUnsigned)) {
                return MS::kFailure;
        }
		if (MS::kSuccess != mySyntax.addFlag(kTransparencyFlag, kTransparencyFlagLong, MSyntax::kDouble)) {
                return MS::kFailure;
        }
		if (MS::kSuccess != mySyntax.addFlag(kSpacingFlag, kSpacingFlagLong, MSyntax::kDouble)) {
                return MS::kFailure;
        }

        return MS::kSuccess;
  }