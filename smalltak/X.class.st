Class {
	#name : #X,
	#superclass : #Object,
	#instVars : [
		'new'
	],
	#category : #covarianza
}

{ #category : #operations }
X >> create [
	Transcript show: 'crea tipo B desde X'.
	^ ImplementsB new.
]

{ #category : #operations }
X >> receive: param [
	Transcript show: 'recibido tipo B desde X'
]
