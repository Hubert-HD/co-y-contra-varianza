Class {
	#name : #Y,
	#superclass : #X,
	#category : #covarianza
}

{ #category : #operations }
Y >> create [
	Transcript show: 'crea tipo C desde Y'.
	^ ImplementsC new.
]

{ #category : #operations }
Y >> receive: param [
	Transcript show: 'recibido tipo C desde Y'
]
