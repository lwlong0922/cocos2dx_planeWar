#include "SelectScene.h"

#include "DataClass.h"
#include "DataMgr.h"
#include "GameMapScene.h"

SelectScene::~SelectScene()
{
}

bool SelectScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	m_nSelectIndex = 0;
	auto visibleSize = Director::getInstance()->getVisibleSize();


	auto backGround = Sprite::createWithSpriteFrameName("backGround.jpg");
	backGround->setContentSize(visibleSize);
	backGround->setAnchorPoint(Vec2::ZERO);

	addChild(backGround, -1);


	PageView* pPageView = PageView::create();
	pPageView->setContentSize(Size(230, 350));
	const float selectScale = 2.0f, normalScale = 1.5f;
	const int rotation3D = 45;
	pPageView->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	pPageView->setPosition(visibleSize / 2);

	auto allData = CDataMgr::getInstance()->getMgr("gameMapDtMgr")->getAllDatas();


	for (int i = 0; i < allData.size(); i++)
	{
		auto layout = Layout::create();
		auto sprite = Sprite::createWithSpriteFrameName(static_cast<CGameMapDt*>(allData[i])->mapName);
		sprite->setContentSize(visibleSize / 3);
		sprite->setPosition(pPageView->getContentSize() / 2);
		layout->addChild(sprite);
		pPageView->addPage(layout);
	}


	this->changeSprite(pPageView, 0, selectScale);
	pPageView->addEventListener(
		static_cast<ScrollView::ccScrollViewCallback>([=](Ref* pSender, ScrollView::EventType type)
	{
		if (ScrollView::EventType::CONTAINER_MOVED == type)
		{
			auto anchorX = visibleSize.width / 2 - pPageView->getContentSize().width / 2;
			for (int i = 0; i < pPageView->getChildrenCount(); i++)
			{
				Layout* pLayout = static_cast<Layout*>(pPageView->getItem(i));

				if (abs(pLayout->getWorldPosition().x - anchorX) < pPageView->getContentSize().width)
				{
					auto diff = abs(pLayout->getWorldPosition().x - anchorX);
					Sprite* pSprite = static_cast<Sprite*>(pLayout->getChildren().back());
					pSprite->setScale(selectScale -
						2 * (selectScale - normalScale)*diff / pPageView->getContentSize().width);

					int ry = (rotation3D)* 2 * diff / pPageView->getContentSize().width;
					ry = pLayout->getWorldPosition().x - anchorX < 0 ? ry : -ry;
					pSprite->setRotation3D(Vec3(0, ry, 0));
					m_nSelectIndex = i;
					// log("%d", m_nSelectIndex);
				}
			}
		}
	}));
	addChild(pPageView);

	Button* pStartBtn = Button::create("btn_fight.png", "", "", TextureResType::PLIST);
	pStartBtn->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 1 / 3.0));
	pStartBtn->setScale(0.6f);
	pStartBtn->addClickEventListener([=](Ref* pSender)
	{
		auto gameMapScene = GameMapScene::create();
		gameMapScene->addBg(static_cast<CGameMapDt*>(allData[m_nSelectIndex])->mapName);
		Director::getInstance()->replaceScene(gameMapScene);
	});
	addChild(pStartBtn);
	return true;
}

SelectScene::SelectScene()
{
}
void SelectScene::changeSprite(PageView* pPageView, int nIndex, float detal)
{
	Layout* pLayeout = static_cast<Layout*>(pPageView->getItem(nIndex));
	Sprite* pSprite = static_cast<Sprite*>(pLayeout->getChildren().back());
	pSprite->setScale(detal);
}